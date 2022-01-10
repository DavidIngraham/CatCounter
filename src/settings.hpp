#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>

class SettingsParser
{
    public:
        SettingsParser(int argc, char *argv[]);

        enum class mode_t {mode_none, mode_help, mode_file, mode_cli};
        
        mode_t get_mode(void) { return m_mode; }
        bool is_valid(void) { return m_valid; }
        bool is_strict(void) { return m_strict_matching; }
        bool is_case_sensitive(void) { return m_case_sensitive; }
        std::string get_filepath(void) { return m_filepath; }
        std::string get_user_string(void) { return m_user_string; }

    private:
        bool m_valid = false;
        mode_t m_mode = SettingsParser::mode_t::mode_none;
        std::string m_filepath ="";
        std::string m_user_string="";
        bool m_case_sensitive = false;
        bool m_strict_matching = false;
};


#endif