#include "settings.hpp"
#include <string.h>


SettingsParser::SettingsParser(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        // Abort if the user provided no arguments
        m_valid = false;
        return;
    } 
    // Parse the arguments according to the active mode
    if (strcmp(argv[1], "help") == 0)
    {
        m_mode = SettingsParser::mode_t::mode_help;
        m_valid = true;
        return;
    } else if (strcmp(argv[1], "cli") == 0)
    {
        m_mode = SettingsParser::mode_t::mode_cli;
        if (argc < 3)
        {
            // Mark as invalid if user did not provide input
            m_valid = false;
            return;
        }
        m_user_string = argv[2];
        m_valid = true;

    } else if (strcmp(argv[1], "file") == 0)
    {
        m_mode = SettingsParser::mode_t::mode_file;
        if (argc < 3)
        {
            // Mark as invalid if user did not provide filename
            m_valid = false;
            return;
        }
        m_filepath = argv[2];
        m_valid = true;

    }

    // Parse optional settings
    for (int i=3; i<(argc); i++)
    {
        if (strcmp(argv[i], "--case-sensitive") == 0) 
        {
            m_case_sensitive = true;
        } else if (strcmp(argv[i], "--strict") == 0)
        {
            m_strict_matching = true;
        } else {
            m_valid = false;
        }
    }

}