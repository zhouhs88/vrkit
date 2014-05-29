
#ifndef _VRKIT_COMMAND_LINE_CONFIG_H_
#define _VRKIT_COMMAND_LINE_CONFIG_H_

#include <vector>
#include <string>
#include <string.h>
#include <stdexcept>
#include "base/configuration.h"

namespace vrkit {
    class CommandLineConfig : public Configuration {
        public:
            CommandLineConfig();
            ~CommandLineConfig();
            bool parse(int argc, char* argv[]);     
            // has configruation parameter
            bool hasConfigParameter(const char *key, const char *section = NULL);

            // get configuration value by key
            bool get(const char *key, std::string &val, const char *section = NULL);
            bool get(const char *key, int &val, const char *section = NULL);
            bool get(const char *key, bool &val, const char *section = NULL);
            bool get(const char *key, float &val, const char *section = NULL);
            bool getConfigFile(std::string& file);
            bool getWorkPath(std::string& path);
            bool getLogLevels(std::string& val);
            bool getPluginPath(std::string& val);
            bool getEnginPath(std::string& val);
            bool getMediaEngine(std::string& val);
        private:
            std::map<std::string, std::string> m_options;
    };
}; // namespace
#endif // _VRKIT_COMMAND_LINE_CONFIG_H_
