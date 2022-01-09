#include "wordcounter.hpp"
#include <algorithm>
#include <cctype>

WordCounter::WordCounter(std::string word, bool case_sensitive) 
{
    // Initialize word counter with standard settings
    m_word = word;
    m_case_sensitive = case_sensitive;
}

unsigned long int WordCounter::count(std::string input_string)
{
    if ( !m_case_sensitive )
    {
        to_lower(input_string);
    }

    std::size_t pos = 0;
    unsigned long int count = 0;
    while (pos != std::string::npos)
    {
        pos = input_string.find(m_word, pos);
        if (pos != std::string::npos)
        {
            count++;
            pos += 1;
        }
    }
    return count;
}

void WordCounter::to_lower(std::string &str) 
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ 
        return std::tolower(c);
    });
    
}