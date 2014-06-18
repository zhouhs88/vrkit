
#ifndef _VRKIT_USER_CONFIG_H_
#define _VRKIT_USER_CONFIG_H_

#include "base/configuration.h"
#include <string>
#include <map>
#include <utility>

namespace vrkit {
    class ConfigFile;

    class UserConfig : public Configuration {
        public:
            UserConfig(const std::string& configFile);
            ~UserConfig();
            // has configruation parameter
            bool hasConfigParameter(const char *key, const char *section = NULL);

            // get configuration value by key
            bool get(const char *key, std::string &val, const char *section = NULL);
            bool get(const char *key, int &val, const char *section = NULL);
            bool get(const char *key, bool &val, const char *section = NULL);
            bool get(const char *key, float &val, const char *section = NULL);
            bool getWorkPath(std::string& path);
            bool getLogLevels(std::string& val);
            bool getPluginPath(std::string& val);
            bool getEnginPath(std::string& val);
            bool getMediaEngine(std::string& val);
        private:
            ConfigFile* m_configFile;
    };
} // namespace vrkit 
#endif // _VRKIT_USER_CONFIG_H_
