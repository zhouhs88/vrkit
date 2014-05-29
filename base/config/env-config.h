
#ifndef _VRKIT_ENVIRONMENT_CONFIG_H_
#define _VRKIT_ENVIRONMENT_CONFIG_H_

#include <string>
#include <string.h>
#include <vector>
#include "base/configuration.h"

namespace vrkit {
    class EnvironmentConfig : public Configuration {
        public:
            EnvironmentConfig();
            ~EnvironmentConfig();
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
    };
} // namespace
#endif // _VRKIT_ENVIRONMENT_CONFIG_H_
