/* catcounter.cpp
   
   CatCounter is a program for counting "cat"s.

*/

#include "wordcounter.hpp"
#include "settings.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

std::string magic_word = "cat";

void print_help(void)
{
   const char *help = R"""(CatCounter counts "cat"s. 

Use it to find the number of occurences of the word "cat" in your string or text file.

Usage:
   catcounter <mode> <input> [options]

Mode: 
   "help": display this help message.
   "cli": provide your string in the "input" field.
   "file: provide the path of your text file in the "input" field

Settings: 
   "--strict": Will only find the "cat" separated by whitespace.
   "--case-sensitive": 4335

Examples:
   catcounter arg "calico cats are a cat above" --strict
   catcounter file ../test/test.txt --case-sensitive
   )""";

   std::cout << help;

}

WordCounter get_wordcounter(SettingsParser s)
{
   return WordCounter(magic_word, s.is_case_sensitive(), s.is_strict());
}

std::string read_from_file(std::string filepath) 
{
   std::string out = "";
   std::ifstream file (filepath);
   if (file.is_open())
   {
      std::stringstream s;
      s << file.rdbuf();
      out = s.str();
      file.close();
   } else {
      std::cout << "Error: Failed to Open File: " << filepath << std::endl;
      exit(1);
   }
   return out;
   
}

void print_result(uint64_t count)
{
   if (count ==1 ) {
      std::cout << "1 \'cat\' was found in the given string \n";
   } else {
      std::cout << count << " \'cat\'s were found in the given string \n";
   }
}

int main(int argc, char *argv[]) 
{
   SettingsParser settings = SettingsParser(argc, argv);
   std::string user_text = "";
   

   switch (settings.get_mode())
   {
      case SettingsParser::mode_t::mode_cli:
         if (!settings.is_valid())
         {
            std::cout << "Invalid usage. Please provide a string when using cli mode. \n";
            print_help();
            exit(1);
         }
         user_text = settings.get_user_string();
         break;

      case SettingsParser::mode_t::mode_file:
         if (!settings.is_valid())
         {
            std::cout << "Invalid usage. Please provide a file path. \n";
            print_help();
            exit(1);
         }
         user_text = read_from_file(settings.get_filepath());
         break;
      case SettingsParser::mode_t::mode_help:
      case SettingsParser::mode_t::mode_none:
      default:
         print_help();
         exit(0);
   }
   uint64_t count = get_wordcounter(settings).count(user_text);
   print_result(count);

   return 0;
}