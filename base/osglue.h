//
//  osglue.h
//  speech waveform file input implementation 
//  wrapper for native os interface

#ifndef _VRKIT_OSGLUE_H_
#define _VRKIT_OSGLUE_H_

#include "base/base.h"
#include <iostream>
#include <string>

#ifndef WIN32
#include <time.h>
#include <Winsock2.h>
#else
#include <sys/time.h>
#endif

#include <error.h>
#include <signal.h>
#include <assert.h>

namespace vrkit {
    namespace os {
        typedef double Time;

        // initialize os glue environment
        bool initialize(int argc, char *argv[])
        void exit(int code);
        void error(int code, char *msg, ...);
        void registerModule(const std::string &module, const std::string &ver);


    } // namespace os

} // namespace vrkit
#endif  // _VRKIT_TEMPLATE_H_
