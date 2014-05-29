//
//  audio-linux.cpp
//  audio input and output on linux

#include "base/audio/audio-linux.h"

using namespace vrkit;

AudioInLInux::AudioInLinux()
{}
virtual AudioInLinux::~AudioInLinux()
{}
const std::string& AudioInLinux::getAudioName()
{}
int AudioInLinux::open(MemoryHeap *heap, os::Time *samPeriod, 
        os::Time winDur, os::Time frPeriod)
{}
void AudioInLinux::attachBuffer(int size)
{}
void AudioInLinux::start(int sig)
{}
void AudioInLinux::stop()
{}
void AudioInLinux::close()
{}
int AudioInLinux::getFramesInAudio()
{}
int AudioInLinux::getSamplesInAudio()
{}
int AudioInLinux::getAIStatus()
{}
float AudioInLinux::getCurrentVol()
{}
int AudioInLinux::getSamplsInFrame()
{}
void AudioInLinux::getAudioData(int nframes, float *buf)
{}
void AudioInLinux::getRawAudio(int nsamples, short *buf)
{}
int  AudioInLinux::getReplyBuffer(int nsamples, short *buf)
{}
int AudioInLinux::controlDevice(int *mask)
{}
void AudioInLinux::fillBufferFromAudio(int min)
{}
void AudioInLinux::stopAndFlushAudio(bool defered)
{}
short AudioInLinux::getSampleFromBuffer()
{}
void AudioInLinux::fillBufferFromAudio(int min)
{}
void AudioInLinux::signalFillBuferAndStopAudio(AudioIn *in) 
{}

