//
//  wave-form-file.cpp
//  speech waveform file input implementation 

#include "base/waveform-file.h"
#include "base/format/ms-wave.h"
#include "base/format/aiff-wave.h"

using namespace vrkit;

int WaveFormFile::initialize()
{
    return 0;
}

WaveFormFile::WaveFormFile()
{}

WaveFormFile* 
WaveFormFile::create(MemoryHeap *mem, char *fname, WaveFileFormat fmt,
                     Time winDur, Time frPeriod, Time *sampPeriod)
{
    assert(mem != NULL);
    assert(sampPeriod != NULL);
    assert(fname != NULL);

    WaveFormFile *wave = NULL;
    switch (fmt) {
        case WAV: 
            wave = new MsWave(mem, fname, fmt, winDur, frPeriod, sampPeriod); 
            break;
        case AIFF: 
            wave = new AIFFWave(mem, fname, fmt, winDur, frPeriod, sampPeriod); 
            break;
        default: 
           return NULL;
    }

    // initialize attribute
    wave->m_mem = mem;
    wave->m_fmt = fmt;
    wave->m_frSize = 0;
    wave->m_frRate = 0;
    wave->m_nSamples = 0;
    wave->m_frIndex = 0;

    // handle extended file name
    // m_file = new std::ifstream(fname

    // get file header
    



}

WaveFormFile::~WaveFormFile()
{
}


void WaveFormFile::zeroWave()
{}
int  WaveFormFile::getFramesInWave()
{}
int  WaveFormFile::getSampsInWaveFrame()
{}

void WaveFormFile::getFrame(int nframes, float *buf)
{}
Wave* WaveFormFile::openWaveOutput()
{}
void WaveFormFile::appendWaveSample(long nsamples, short *buf)
{}
void WaveFormFile::closeWaveOutout(Wave *w, WaveFileFormat fmt, char *name)
{}
WaveFileFormat:: WaveFormFile::getWaveFormat()
{
    return m_fmt;
}
void WaveFormFile::dumpWaveInfo(std::ostream &os)
{}
