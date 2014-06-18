
#include "base/module.h"
#include "base/meta-config.h"
#include "base/config/config-file.h"
#include "base/config/env-config.h"
#include "base/config/user-config.h"
#include "base/config/cmdline-config.h"
#include "base/osglue.h"

using namespace vrkit;

Module::Module(ModuleLoader* loader, const std::string &name)
{}

Module::~Module()
{}

bool Module::create(int argc, char *argv[])
{
    try {
        MetaConfig *config = MetaConfig::getInstance();
        
        // parse command line to get options
        CommandLineConfig *cmdlineConfig = new CommandLineConfig();
        if (!cmdlineConfig->parse(argc, argv)) {
            os::error("illegal command line option\n");
            delete cmdlineConfig;
            return false;
        }
        config->registerConfiguration(cmdlineConfig);

        // create environment configuration
        EnvironmentConfig *envConfig = new EnvironmentConfig();
        config->registerConfiguration(envConfig);

        // create user Configuration
        std::string configFile;
        if (cmdlineConfig->getConfigFile(configFile)) {
            UserConfig *userConfig = new UserConfig(configFile);
            config->registerConfiguration(userConfig);
        }
#if 0
        // check import options
        if (!checkConfigurations()) {
            os::error("illegal configuration\n");
            return false;
        }
#endif
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
