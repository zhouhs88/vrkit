/// 
/// module-loader.h
/// load module from lib file
///
#ifndef _VRKIT_MODULE_LOADER_H_
#define _VRKIT_MODULE_LOADER_H_

#include "base/base.h"
#include "base/module.h"

namespace vrkit {

class ModuleLoader {
    public:
        static ModuleLoader* getInstance();
        bool initialize(int argc, char *argv[]);
        void loadModuleAllModules();
        void terminateAllModules();
        Module* getModule(const std::string &module);
        Module* loadModule(const std::string &module);
        void terminateModule(const std::string &module);
    private:
        ModuleLoader();
        ~ModuleLoader();
        std::map<std::string, Module*> m_modules;
};

} // namespace vrkit
#endif // _VRKIT_MODULE_LOADER_H_
