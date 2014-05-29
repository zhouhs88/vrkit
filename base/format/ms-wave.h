//
//  ms-wave.h
//  speech waveform file input implementation 

#ifndef _VRKIT_MS_WAVE_FILE_H_
#define _VRKIT_MS_WAVE_FILE_H_

#include "base/waveform-file.h"

namespace vrkit {

class MsWave : public WaveFormFile {
    public:
        explicit MsWave(MemoryHeap *mem, char *fname, WaveFileFormat fmt,
                        Time winDur, Time frPeriod, Time *sampPeriod)throw;
        ~MsWave();
        long getHeaderInfo(std::ifstream &file, InputAction *action);
        void putHeaderInfo();
    protected:
};

} // namespace vrkit
#endif  // _VRKIT_MS_WAVE_FILE_H_
