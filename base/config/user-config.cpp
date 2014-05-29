
#include "base/config/user-config.h"
#include <limits.h>
#include <assert.h>
#include <algorithm>

using namespace vrkit;

#define UNINT16_MAX 65535 
#define UNINT16_MIN 0

const std::string GENERAL_SECTION = "general";
const std::string APPLICATION_NAME = "name";
const std::string CONFIG_FILE = "owl.conf";
const std::string IFACE_KEY = "network-interface";
const std::string PORT_KEY = "port";
const std::string WORK_PATH = "path";
const std::string ENABLED_KEY = "enabled";
const std::string UPNP_ENABLED_KEY = "upnp-" + ENABLED_KEY;
const std::string TITLE_KEY = "title";
const std::string TRANSCODING_KEY = "enable-transcoding";
const std::string ALLOW_UPLOAD_KEY = "allow-upload";
const std::string ALLOW_DELETION_KEY = "allow-deletion";
const std::string LOG_LEVELS_KEY = "log-level";
const std::string PLUGIN_PATH_KEY = "plugin-path";
const std::string ENGINE_PATH_KEY = "engine-path";
const std::string MEDIA_ENGINE_KEY = "media-engine";
const std::string UPLOAD_FOLDER_KEY = "upload-folder";
const std::string VIDEO_UPLOAD_DIR_PATH_KEY =
                                        "video-" + UPLOAD_FOLDER_KEY;
const std::string MUSIC_UPLOAD_DIR_PATH_KEY =
                                        "music-" + UPLOAD_FOLDER_KEY;
const std::string PICTURE_UPLOAD_DIR_PATH_KEY =
                                        "picture-" + UPLOAD_FOLDER_KEY;

UserConfig::UserConfig(const std::string& configFile)
{
    m_configFile = new ConfigFile(configFile);
}

UserConfig::~UserConfig()
{
    if (m_configFile)
        delete m_configFile;
    m_configFile = NULL;
}

bool UserConfig::getApplicationName(std::string& name)
{
    return m_configFile->getString(GENERAL_SECTION, APPLICATION_NAME, name);
}

bool UserConfig::getUPnPEnabled(bool& result)
{
    return m_configFile->getBool(GENERAL_SECTION, UPNP_ENABLED_KEY, result);
}

bool UserConfig::getInterfaces(std::vector<std::string>& val)
{
    return m_configFile->getStrings(GENERAL_SECTION, IFACE_KEY, val);
}

bool UserConfig::getInterface(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, IFACE_KEY, val);
}

bool UserConfig::getPort(unsigned int& port)
{
    return m_configFile->getInt(GENERAL_SECTION, PORT_KEY, port);
}

bool UserConfig::getWorkPath(std::string& path)
{
    return m_configFile->getString(GENERAL_SECTION, WORK_PATH, path);
}

bool UserConfig::getTranscoding(bool& result)
{
    return m_configFile->getBool(GENERAL_SECTION, TRANSCODING_KEY, result);
}

bool UserConfig::getAllowUpload(bool& result)
{
    return m_configFile->getBool(GENERAL_SECTION, ALLOW_UPLOAD_KEY, result);
}

bool UserConfig::getAllowDeletion(bool& result)
{
    return m_configFile->getBool(GENERAL_SECTION, ALLOW_DELETION_KEY, result);
}

bool UserConfig::getLogLevels(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, LOG_LEVELS_KEY, val);
}

bool UserConfig::getPluginPath(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, PLUGIN_PATH_KEY, val);
}

bool UserConfig::getEnginPath(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, ENGINE_PATH_KEY, val);
}

bool UserConfig::getMediaEngine(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, MEDIA_ENGINE_KEY, val);
}

bool UserConfig::getVideoUploadFolder(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, VIDEO_UPLOAD_DIR_PATH_KEY, val);
}

bool UserConfig::getMusicUploadFolder(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, MUSIC_UPLOAD_DIR_PATH_KEY, val);
}

bool UserConfig::getPictureUploadFolder(std::string& val)
{
    return m_configFile->getString(GENERAL_SECTION, PICTURE_UPLOAD_DIR_PATH_KEY, val);
}

bool UserConfig::getEnabled(const std::string& section, bool& result)
{
    return m_configFile->getBool(section, ENABLED_KEY, result);
}

bool UserConfig::getTitle(const std::string& section, std::string& val)
{
    return m_configFile->getString(section, TITLE_KEY, val);
}
