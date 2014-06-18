	
#include "base/meta-config.h"
#include <assert.h>

using namespace vrkit;

MetaConfig::MetaConfig()
{}

MetaConfig::~MetaConfig()
{}

MetaConfig* MetaConfig::getInstance()
{ 
    static MetaConfig metaConfig;
    return &metaConfig;
}

void MetaConfig::registerConfiguration(Configuration* config)
{
    if(config) 
        m_configs.push_back(config);
}

bool MetaConfig::getDataPath(std::string& path)
{
    getWorkPath(path);
    path += "/data/";
    return true;
}
bool MetaConfig::getSysConfigPath(std::string& path)
{
    throw new ConfigurationError("No value available");
    return true;
}

bool MetaConfig::getWorkPath(std::string& path)
{   
    for (size_t i = 0; i < m_configs.size(); i++) {
        Configuration* config = m_configs[i];
        if (config->getWorkPath(path))
            return true;
    }
    throw new ConfigurationError("No value available");
    return false;
}


bool MetaConfig::getLogLevels(std::string& val)
{
    for (size_t i = 0; i < m_configs.size(); i++) {
        Configuration* config = m_configs[i];
        if (config->getLogLevels(val))
            return true;
    }	
	
    throw new ConfigurationError("No value available");
    return false;
}

bool MetaConfig::getPluginPath(std::string& path)
{  
    for (size_t i = 0; i < m_configs.size(); i++) {
        Configuration* config = m_configs[i];
        if (config->getPluginPath(path))
            return true;
    }	
    throw new ConfigurationError("No value available");
    return false;
}

bool MetaConfig::getEnginPath(std::string& val)
{      
    for (size_t i = 0; i < m_configs.size(); i++) {
        Configuration* config = m_configs[i];
        if (config->getEnginPath(val))
            return true;
    }	
    throw new ConfigurationError("No value available");
    return false;
}

bool MetaConfig::getMediaEngine(std::string& val)
{  
    for (size_t i = 0; i < m_configs.size(); i++) {
        Configuration* config = m_configs[i];
        if (config->getMediaEngine(val))
            return true;
    }
    throw new ConfigurationError("No value available");
    return false;
} 

