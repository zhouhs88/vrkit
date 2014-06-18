//
//  wave-form-file.h
//  speech waveform file input implementation 

#ifndef _VRKIT_WAVE_FILE_H_
#define _VRKIT_WAVE_FILE_H_

#include "base/osglue.h"
#include "base/time.h"
#include "base/memory.h"


namespace vrkit {
    class Wave;
    class InputAction;

enum WaveFileFormat {
    WAV,  // Microsoft wave format
    AIFF, // Apple wave forme
    UNKNOWN
};


class WaveFormFile {
    public:
        // initialize wave form file module
        static int initialize();
        // create wave form file according to format
        static WaveFormFile*  create(MemoryHeap *mem, char *fname,
                                     WaveFileFormat fmt, Time winDur, Time frPeriod, 
                                     Time *sampPeriod);
        virtual ~WaveFormFile();
        void zeroWave();
        int  getFramesInWave();
        int  getSampsInWaveFrame();
        void getFrame(int nframes, float *buf);
        Wave* openWaveOutput();
        void appendWaveSample(long nsamples, short *buf);
        void closeWaveOutout(Wave *w, WaveFileFormat fmt, char *name);
        WaveFileFormat getWaveFormat(); 
        void dumpWaveInfo(std::ostream &os);
    protected:
        virtual long getHeaderInfo(std::ifstream &file, InputAction *action);
        virtual void putHeaderInfo();
    protected:
        std::ifstream *m_file;
        MemoryHeap *m_mem;
        WaveFileFormat m_fmt;
        bool m_isPipe;
        Time m_sampPeriod;
        int m_hdrSize;
        long m_nSamples;
        long m_nAvail;
        int m_frSize;
        int m_frRate;
        int m_frIndex;
    private:
        WaveFormFile();
};

} // namespace vrkit
#endif  // _VRKIT_WAVE_FILE_H_
