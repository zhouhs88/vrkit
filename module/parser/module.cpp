///
/// module.cpp
/// parser module entry 
///

#include "base/module.h"
#include "base/module-loader.h"
#include "parser.h"

vrkit::Module*
module_load(vrkit::ModuleLoader *loader, const std::string &name)
{
    if (name == "parser")
        return new ParserModule(loader, name);
    else
        return NULL;

}

void module_exit()
{}

