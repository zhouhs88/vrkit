// meta-config.h
// all meta configuration item should be accessed by it

#ifndef _VRKIT_META_CONFIG_H_
#define _VRKIT_META_CONFIG_H_

#include "base/configuration.h"

namespace vrkit {
    
    class MetaConfig : public Configuration {
        public:
            static MetaConfig* getInstance();

            // terminate the configuration
            static void terminate();

            // register configuration items
            void registerConfiguration(Configuration *config);            

            // has configruation parameter
            bool hasConfigParameter(const char *key, const char *section = NULL);

            // get configuration value by key
            bool get(const char *key, std::string &val, const char *section = NULL);
            bool get(const char *key, int &val, const char *section = NULL);
            bool get(const char *key, bool &val, const char *section = NULL);
            bool get(const char *key, float &val, const char *section = NULL);

            // methods form configuration interface
            bool getSysConfigPath(std::string &path);
            bool getWorkPath(std::string &path);
            bool getDataPath(std::string &path);
            bool getLogLevels(std::string &val);
            bool getPluginPath(std::string &val);
            bool getEnginPath(std::string &val);
            bool getMediaEngine(std::string &val);
            void print(std::ostream &os);
        private:
            MetaConfig();
            ~MetaConfig();
        private:
            int m_argc;
            char** m_argv;
            std::vector<Configuration*> m_configs;
    };

}  // namespace vrkit 
#endif // _VRKIT_META_CONFIG_H_
