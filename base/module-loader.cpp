/// 
/// module-loader.cpp
/// load module from lib file
///
#include "base/module-loader.h"

using namespace vrkit;

ModuleLoader::ModuleLoader()
{}
ModuleLoader::~ModuleLoader()
{}
ModuleLoader* ModuleLoader::getInstance()
{
    static ModuleLoader loader;
    return &loader;
}
void ModuleLoader::loadModuleAllModules()
{}
void ModuleLoader::terminateAllModules()
{}
Module* ModuleLoader::getModule(const std::string &module)
{
    return NULL;
}
Module* ModuleLoader::loadModule(const std::string &module)
{
    return NULL;
}
void ModuleLoader::terminateModule(const std::string &module)
{}
