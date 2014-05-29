/// 
/// module-loader.cpp
/// load module from lib file
///
#include "base/module-loader.h"

using namespace vrkit;

ModuleLoader::Module()
{}
ModuleLoader::~Module()
{}
ModuleLoader* ModuleLoader::getInstance()
{}
void ModuleLoader::loadModuleAllModules()
{}
void ModuleLoader::terminateAllModules()
{}
Module* ModuleLoader::getModule(const std::string &module)
{}
Module* ModuleLoader::loadModule(const std::string &module)
{}
void ModuleLoader::terminateModule(const std::string &module)
{}
