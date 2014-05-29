#include "base/config/env-config.h"
#include <stdlib.h>

using namespace dlna;

static std::string OWL_PREFIX = "VRKIT";
static std::string DISABLE_PREFIX = OWL_PREFIX + "_DISABLE";
static std::string ENABLED_KEY = "ENABLED";
static std::string WORK_PATH = OWL_PREFIX + "_PATH";
static std::string LOG_LEVELS_ENV = OWL_PREFIX + "_LOG";
static std::string PLUGIN_PATH_ENV = OWL_PREFIX + "_PLUGIN_PATH";
static std::string ENGINE_PATH_ENV = OWL_PREFIX + "_ENGINE_PATH";
static std::string MEDIA_ENGINE_ENV = OWL_PREFIX + "_MEDIA_ENGINE";


EnvironmentConfig::EnvironmentConfig()
{}

EnvironmentConfig::~EnvironmentConfig()
{}

static bool getStringVariable(const std::string& inVal, std::string& outVal)
{
    char* val = getenv(inVal.c_str());
    if (!val)
        return false;
    outVal = val; 
    return true;
}

static bool getIntVariable(const std::string& val, unsigned int min, unsigned int max, unsigned int& ret)
{
    char* result = getenv(val.c_str());
    if (!result) 
        return false;

    int tval = atoi(result);
    if (tval < 0)
        ret = min;
    else if ((unsigned)tval > max)
        ret = max;
    else if ((unsigned)tval < min)
        ret = min;
    else
        ret = tval;
    return true;
}

static bool getBoolVariable(const std::string& val, bool& result)
{
    char* tval = getenv(val.c_str());
    if (!tval)
        return false;
    std::string item = tval;
    if (item == "true")
        result = true;
    else if (item == "false")
        result = false;
    else
        throw new ConfigurationError("Invalid option value");
    return true;
}

bool EnvironmentConfig::getWorkPath(std::string& path)
{
    return getStringVariable(WORK_PATH, path);
}

bool EnvironmentConfig::getLogLevels(std::string& val)
{
    return getStringVariable(LOG_LEVELS_ENV, val);
}

bool EnvironmentConfig::getPluginPath(std::string& val)
{
    return getStringVariable(PLUGIN_PATH_ENV, val);
}

bool EnvironmentConfig::getEnginPath(std::string& val)
{
    return getStringVariable(ENGINE_PATH_ENV, val);
}

bool EnvironmentConfig::getMediaEngine(std::string& val)
{
    return getStringVariable(MEDIA_ENGINE_ENV, val);
}
