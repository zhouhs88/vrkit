
#include "base/module.h"
#include "base/config/env-config.h"
#include "base/config/user-config.h"
#include "base/config/cmdline-config.h"

using namespace vrkit;

Module::Module(const std::string &name):m_title(name)
{}

Module::~Module()
{}

bool Module::create(int argc, char *argv[])
{
    try {
        MetaConfig *config = MetaConfig::getInstance();
        
        // parse command line to get options
        CmdlineConfig *cmdlineConfig = new CommandLineConfig();
        if (!cmdlineConfig->parse(argc, argv)) {
            os::error("illegal command line option\n");
            delete cmdlineConfig;
            return false;
        }
        config->registerConfiguration(cmdlineConfig);

        // create environment configuration
        EnvConfig *envConfig = new EnvironmentConfig();
        config->registerConfiguration(envConfig);

        // create user Configuration
        std::string configFile;
        if (cmdlineConfig->getConfigFile(configFile)) {
            UserConfig *userConfig = new UserConfig(config);
            config->registerConfiguration(userConfig);
        }

        // check import options
        if (!checkConfigurations()) {
            os::error("illegal configuration\n");
            return false;
        }
    }
    catch (...) {
        std::string name = getTitle();
        os::error("exception occured in applicaiton(%s) creation\n", name.c_str());
        return false;
    }

    return true;
}

void Module::terminate()
{
    // terminate meta-configuration
    MetaConfig::terminate();
}

const std::string& Module::getTitle()
{
    return m_title;
}
