//
//  audio.h
//  audio input and output 

#ifndef _VRKIT_AUDIO_LINUX_H_
#define _VRKIT_AUDIO_LINUX_H_

#include "base/audio.h"

namespace vrkit {

class AudioInLinux : public AudioIN{
    public:
        AudioInLinux();
        virtual ~AudioInLinux();
        const std::string& getAudioName();
        int open(MemoryHeap *heap, os::Time *samPeriod, os::Time winDur, os::Time frPeriod);
        void attachBuffer(int size);
        void start(int sig);
        void stop();
        void close();
        int getFramesInAudio();
        int getSamplesInAudio();
        int getAIStatus();
        float getCurrentVol();
        int getSamplsInFrame();
        void getAudioData(int nframes, float *buf);
        void getRawAudio(int nsamples, short *buf);
        int  getReplyBuffer(int nsamples, short *buf);
        int controlDevice(int *mask);
    protected:
        void fillBufferFromAudio(int min);
        void stopAndFlushAudio(bool defered);
        short getSampleFromBuffer();
        void fillBufferFromAudio(int min);
        void signalFillBuferAndStopAudio(AudioIn *in); 
};

class AudioOutLinux : AudioOut {
    public:
        AudioOutLinux();
        ~AudioOutLinux();
        const std::string& getAudioName();
        int open(MemoryHeap *heap, os::Time *samPeriod);
        void start(long nsamples);
        void playReplayBuffer(AudioIn *in);
        void close();
        void setVol(int volume);
        float getCurrentVol();
        int getSamplesToPlay();
        int controlDevice(int *mask);
    protected:
        int outSamples();
        void playAudio(short *buf, int nsamples);
};

} // namespace vrkit
#endif  // _VRKIT_AUDIO_H_
