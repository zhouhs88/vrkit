//
//  audio.cpp
//  audio input and output implementations

#include "base/audio.h"
#include "base/audio/audio-linux.h"

using namespace vrkit; 

static std::string AudioFactory::m_name;

AudioFactory::AudioFactory(){}
AudioFactory::~AudioFactory(){}

bool AudioFactory::initialize(const std::string &os)
{
    AudioFactory::m_name = os;
}

AudioFactory* AudioFactory::getInstance()
{
    static AudioFactory factory;
    return &factory;
}

AudioIn* AudioFactory::createAudioIn()
{
    if (AudioFactory::m_name == "linux")
        return new AudioInLinux();
    else 
        return NULL;

}
AudioOut* AudioFactory::createAudioOut()
{
    if (AudioFactory::m_name == "linux")
        return new AudioOutLinux();
    else
        return NULL;
}
