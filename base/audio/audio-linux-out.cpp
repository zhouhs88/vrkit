//
//  audio-linux.cpp
//  audio input and output on linux

#include "base/audio/audio-linux.h"

using namespace vrkit;

AudioOutLinux::AudioOutLinux()
{}
AudioOutLinux::~AudioOutLinux()
{}
const std::string& AudioOutLinux::getAudioName()
{}
int AudioOutLinux::open(MemoryHeap *heap, os::Time *samPeriod)
{}
void AudioOutLinux::start(long nsamples)
{}
void AudioOutLinux::playReplayBuffer(AudioIn *in)
{}
void AudioOutLinux::close()
{}
void AudioOutLinux::setVol(int volume)
{}
float AudioOutLinux::getCurrentVol()
{}
int AudioOutLinux::getSamplesToPlay()
{}
int AudioOutLinux::controlDevice(int *mask)
{}
int AudioOutLinux::outSamples()
{}
void AudioOutLinux::playAudio(short *buf, int nsamples)
{}
