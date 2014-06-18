//
//  ms-wave.h
//  speech waveform file input implementation 

#ifndef _VRKIT_AIFF_WAVE_FILE_H_
#define _VRKIT_AIFF_WAVE_FILE_H_

#include "base/waveform-file.h"

namespace vrkit {

class AIFFWave : public WaveFormFile {
    public:
        explicit AIFFWave(MemoryHeap *mem, char *fname, WaveFileFormat fmt,
                        Time winDur, Time frPeriod, Time *sampPeriod);
        ~AIFFWave();
        long getHeaderInfo(std::ifstream &file, InputAction *action);
        void putHeaderInfo();
    protected:
};

} // namespace vrkit
#endif  // _VRKIT_AIFF_WAVE_FILE_H_
