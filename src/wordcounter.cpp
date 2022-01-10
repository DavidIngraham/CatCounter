#include "wordcounter.hpp"
#include <algorithm>
#include <cctype>

WordCounter::WordCounter(std::string word, bool case_sensitive, bool strict) 
{   
    m_word = word;
    m_case_sensitive = case_sensitive;
    m_strict = strict;
}

uint64_t WordCounter::count(std::string input_string)
{
    if ( !m_case_sensitive )
    {
        to_lower(input_string);
    }
    
    std::size_t pos = 0;
    uint64_t count = 0;
    while (pos != std::string::npos)
    {
        pos = input_string.find(m_word, pos);
        if (pos != std::string::npos)
        {
            if (m_strict) 
            {
                // If the found instance of cat is at the beginning or is proceeded by whitespace 
                // and is followed by whitespace or is at the end of the string
                int lgt = m_word.length();
                if ((pos==0 || isspace(input_string[pos-1])) &&
                    (isspace(input_string[pos+lgt]) || pos==input_string.length()-lgt))
                {
                    count++;
                }
            } else {
                count++;
            }
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