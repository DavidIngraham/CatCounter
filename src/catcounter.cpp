/* catcounter.cpp
   
   CatCounter is a program for counting "cat"s.
   
   Usage: see README.md

*/

#include "wordcounter.hpp"
#include <iostream>
#include <set>


bool allow_plurals = false;
bool allow_internal_cat = true;
bool case_sensitive = false;

int main(void) 
{
   //Todo: User input
   
   std::string input_string = "KittyCat doggos cat puppers cats";
   std::string magic_word;

   // Populate allowable form of "cat" based on user input settings
   
   if (allow_internal_cat)
   {
      // Note: this will implicitly allow plurals as well
      magic_word = "cat";
   } else if (allow_plurals)
   {
      magic_word = " cats ";
   } else 
   {
      magic_word = " cat ";
   }

   // Validate String  contains valid text - UTF8 vs ASCII?
   //TODO


   WordCounter counter = WordCounter(magic_word, case_sensitive);
   

   std::cout << counter.count(input_string) << std::endl;

   return 0;
}