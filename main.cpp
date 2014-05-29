///
/// main.cpp
/// vrkit entry
///

#include "base/base.h"
#include "base/meta-config.h"
#include "base/module.h"
#include "base/module-loaser.h"

using namespace vrkit;

bool createAndCheckConfigs(int argc, char *argv[])
{
    MetaConfig *metaConfig = MetaConfig::getInstance();
    
    // create environment configuration
    Configuration *config = new EnvironmentConfig();
    metaConfig->registerConfiguration(config);

    // create user Configuration
    config = new UserConfig();
    metaConfig->registerConfiguration(config);

    // check import options
#if 0
    if (!checkConfigurations()) {
        os::error("illegal configuration\n");
        return 0;
    }
#endif
    return true;

}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        os::error("unkown module to load\n");
        return 0;
    }
    // initialize options
    try {

        // initialize configurations
        if (!createAndCheckConfigs(argc, argv)) {
            os::error("illegal options\n");
            return 0;
        }

        // initialize module loader
        ModuleLoader *loader = ModuleLoader::getInstannce();
        loader->initialize(--argc, ++argv);

        // get module name and tell loader to load it
        std::string moduleName = argv[1];
        Module *module = loader->loadModule(moduleName):
        if (!module) {
            os::error("failed to loader module(%s)\n", moduleName.c_str());
            return 0;
        }
        module->run();

        // relase all resources
        ModuleLoader::terminateAllModules();
        MetaConfigurations::terminate();
        return 0;
    }
    catch (...) {
        std::string name = getTitle();
        os::error("exception occured in applicaiton(%s) creation\n", 
                name.c_str());
        return 0;
    }

    return 0;
}

void Module::terminate()
{

}
