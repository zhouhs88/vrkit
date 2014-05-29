//
//  parser.h
//  parse grammar task file to work network 

#ifndef _VRKIT_MODULE_PARSER_H_
#define _VRKIT_MODULE_PARSER_H_

#include "base/mdoule.h"

namespace vrkit {

class Parser : public Module {
    public:
        Parser();
        ~Parser();
        bool create(int argc, char *argv[]);
        int run();
        void terminate();
        void getOption(const std::string &val, std::string &val);
        void setOption(const std::string &val, const std::string &val);
        void getAllOptions(std::vector<std::string> &options);
};

} // namespace vrkit
#endif  // _VRKIT_MODULE_PARSER_H_
