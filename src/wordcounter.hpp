#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

/*  wordcounter.h
    
    Helper class for counting instances of a given string in another string

*/
#include <iostream>
#include <set>

class WordCounter
{
    public:
        WordCounter(std::string word, bool case_sensitive);
        unsigned long int count(std::string input_string);

    private:
        std::string m_word;
        void to_lower(std::string &str);
        bool m_case_sensitive;
};

#endif