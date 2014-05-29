
#ifndef _VRKIT_CONFIGURATION_H_
#define _VRKIT_CONFIGURATION_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


namespace dlna {

    class ConfigurationError : public std::runtime_error {
        public:
            explicit ConfigurationError(const std::string& s):
                std::runtime_error(s) {}

    };
    enum ConfigurationEntry {
        UPNP_ENABLED,
        INTERFACE,
        PORT,
        TRANSCODING,
        ALLOW_UPLOAD,
        ALLOW_DELETION,
        LOG_LEVELS,
        PLUGIN_PATH,
        VIDEO_UPLOAD_FOLDER,
        MUSIC_UPLOAD_FOLDER,
        PICTURE_UPLOAD_FOLDER
    };
    
    class ConfigurationListener {
        public:
            virtual void onConfigurationChanged(ConfigurationEntry entry) = 0;
    };

    class Configuration {
        public:
            Configuration();
            virtual ~Configuration();
            void registerConfigurationListener(ConfigurationListener* listener);
            void unregisterConfigurationListener(ConfigurationListener* listener);
            // has configruation parameter
            virtual bool hasConfigParameter(const char *key, const char *section = NULL);

            // get configuration value by key
            virtual bool get(const char *key, std::string &val, const char *section = NULL);
            virtual bool get(const char *key, int &val, const char *section = NULL);
            virtual bool get(const char *key, bool &val, const char *section = NULL);
            virtual bool get(const char *key, float &val, const char *section = NULL);
            virtual bool getWorkPath(std::string &path) = 0;
            virtual bool getLogLevels(std::string &val) = 0;
            virtual bool getPluginPath(std::string &val) = 0;
            virtual bool getEnginPath(std::string &val) = 0;
            virtual bool getMediaEngine(std::string &val) = 0;
	   protected:
            void onConfigurationChanged(ConfigurationEntry entry);
	        std::vector<ConfigurationListener *> m_listeners;
    };

}  // namespace  

#endif // _VRKIT_CONFIGURATION_H_
