//
//  wave-form-file.cpp
//  speech waveform file input implementation 

#include "base/waveform-file.h"

using namespace vrkit;

int WaveFormFile::initialize()
{
    return 0;
}

WaveFormFile::Wave()
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
        case WaveFileFormat::WAV: 
            wave = new MsWave(); 
            break;
        case WaveFileFormat::AIFF: 
            wave = new AppleWave();
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

WaveFormFile::~Wave()
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
WaveFormFile:: WaveFormFile::getWaveFormat()
{}
void WaveFormFile::dumpWaveInfo(std::ostream &os)
{}
