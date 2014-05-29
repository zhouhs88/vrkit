
#include "base/config/cmdline-config.h"
#include <algorithm>

using namespace vrkit;

struct OptionItem {
    const char* key;
    const char* shortName;
    bool hasValue;
    const char* val;
    const char* description;
} optionItems [] = {
    {"version", "v", false, NULL, "Display version number"},
    {"mode", "m", true, "render|server|ctrlpoint", "Run mode, render or server"},
    {"path", "P", true, NULL, "Work path for dlna"},
    {"config", "c", true, NULL, "Use configuration file instead of user configuration"},
    {"log-level", "g", true, "info|waring|critial", "Log level"},
    {"plugin-path", "u", true, NULL, "PLugin Path"},
    {"engine-path", "e", true, NULL, "Engine Path"},
    {"disable-plugin", "d", true, "true|false", "Disable Plugin"},
    {"plugin-option", "o", true, NULL, "Set plugin options"},
};

static int isValidOptions(std::string& name)
{
    int count = sizeof(optionItems)/sizeof(optionItems[0]); 
    for (int i = 0; i < count; i++) {
        if (strcmp(name.c_str(), optionItems[i].key) == 0) 
            return i;
        if (strcmp(name.c_str(), optionItems[i].shortName) == 0) {
            name = optionItems[i].key;
            return i;
        }
    }
    return -1;
}

bool CommandLineConfig::parse(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        char* item = argv[i];
        // skip symbol '-' to get option key
        std::string key = item + 1;
        // new option found
        if (item[0] == '-') {
            // check wether the option is validy
            int index = -1;
            if ((index = isValidOptions(key)) < 0)
                return false;

            // get option item's value
            std::string value;
            if (optionItems[index].hasValue) {
                while (++i < argc) {
                    if (argv[i][0] == '-') {
                        i--;
                        break;
                    }
                    if (value.empty())
                        value = argv[i];
                    else {
                        value += ";";
                        value += argv[i];
                    }
                }
            }
            // check wether there are two sampe options
            if (m_options.find(key) == m_options.end())
                m_options.insert(std::make_pair(key, value));
            else {
                return false;
            }
        }
    }

    return !m_options.empty();
}

CommandLineConfig::CommandLineConfig()
{
}

CommandLineConfig::~CommandLineConfig()
{
}

bool CommandLineConfig::getWorkPath(std::string& path)
{
    if (m_options.find("path") != m_options.end()) {
        path = m_options["path"];
        return true;
    }
    return false;
}

bool CommandLineConfig::getLogLevels(std::string& val)
{  
    if (m_options.find("log-level") != m_options.end()) {
        val = m_options["log-level"];        
        if (!val.empty()) 
            return true;
    } 

    return false;
}

bool CommandLineConfig::getPluginPath(std::string& val)
{
    if (m_options.find("plugin-path") != m_options.end()) {
        val = m_options["plugin-path"];
        if (!val.empty()) 
            return true;
    } 
    
    return false;
}

bool CommandLineConfig::getEnginPath(std::string& val)
{ 
    if (m_options.find("engine-path") != m_options.end()) {
        val = m_options["engine-path"];
        if (!val.empty()) {
            return true;
        }
    }

    return false;
}

bool CommandLineConfig::getMediaEngine(std::string& val)
{
    return false;
}


bool CommandLineConfig::getConfigFile(std::string& file)
{   
    if (m_options.find("config") != m_options.end()) {
        file = m_options["config"];
        if (!file.empty()) 
            return true;
    }
    
    return false;
}
