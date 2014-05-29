
#ifndef _VRKIT_MODULE_H_
#define _VRKIT_MODULE_H_

#include "base/base.h"

namespace vrkit {

class  ModuleLoader;

class Module {
    public:
        Module(ModuleLoader* loader, const std::string &name);
        virtual ~Module();
        virtual bool create(int argc, char *argv[]);
        virtual int run() = 0;
        virtual void terminate();
        virtual void getOption(const std::string &val, std::string &val);
        virtual void setOption(const std::string &val, const std::string &val);
        virtual void getAllOptions(std::vector<std::string> &options);
};

} // namespace vrkit
#endif // _VRKIT_MODULE_H_
