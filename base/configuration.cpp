/*
 * Copyright (c) 2013 Neusoft
 *
 */


#include "ns-configuration.h"
#include "platform/platform-error.h"
#include <algorithm>

using namespace dlna;



Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}

void Configuration::registerConfigurationListener(ConfigurationListener* listener)
{
    assert(listener != NULL);
    if (find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end())
        m_listeners.push_back(listener);
    else
        platform::error("Configuration:: duplicated listener");
}

void Configuration::unregisterConfigurationListener(ConfigurationListener* listener)
{
    assert(listener != NULL);
    std::vector<ConfigurationListener*>::iterator ite = m_listeners.begin();
    for (; ite != m_listeners.end(); ite++) {
        if (*ite == listener) {
            m_listeners.erase(ite);
            break;
        }
    }
}

void Configuration::onConfigurationChanged(ConfigurationEntry entry)
{
    for (size_t i = 0; i < m_listeners.size(); i++) 
        m_listeners[i]->onConfigurationChanged(entry);
}

    
