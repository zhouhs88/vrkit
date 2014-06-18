//
//  audio.h
//  audio input and output 

#ifndef _VRKIT_AUDIO_H_
#define _VRKIT_AUDIO_H_

#include "base/base.h"
#include "base/time.h"
#include "base/memory.h"
#include "base/osglue.h"

namespace vrkit {

class AudioIn {
    public:
        AudioIn(){}
        virtual ~AudioIn(){}
        const std::string& getAudioName();
        virtual int open(MemoryHeap *heap, Time *samPeriod, Time winDur, Time frPeriod);
        virtual void attachBuffer(int size);
        virtual void start(int sig);
        virtual void stop();
        virtual void close();
        virtual int getFramesInAudio();
        virtual int getSamplesInAudio();
        virtual int getAIStatus();
        virtual float getCurrentVol();
        virtual int getSamplsInFrame();
        virtual void getAudioData(int nframes, float *buf);
        virtual void getRawAudio(int nsamples, short *buf);
        virtual int  getReplyBuffer(int nsamples, short *buf);
        virtual int controlDevice(int *mask);
    protected:
        virtual void stopAndFlushAudio(bool defered);
        virtual short getSampleFromBuffer();
        static void fillBufferFromAudio(int min);
        static void signalFillBuferAndStopAudio(AudioIn *in); 
};

class AudioOut {
    public:
        AudioOut(){}
        virtual ~AudioOut(){}
        virtual const std::string& getAudioName();
        virtual int open(MemoryHeap *heap, Time *samPeriod);
        virtual void start(long nsamples);
        virtual void playReplayBuffer(AudioIn *in);
        virtual void close();
        virtual void setVol(int volume);
        virtual float getCurrentVol();
        virtual int getSamplesToPlay();
        virtual int controlDevice(int *mask);
    protected:
        virtual int outSamples();
        virtual void playAudio(short *buf, int nsamples);
};

class AudioFactory {
    public:
        static AudioFactory* getInstance();
        static bool initialize(const std::string &os);
        AudioIn* createAudioIn();
        AudioOut* createAudioOut();
    private:
        AudioFactory();
        ~AudioFactory();
        static std::string m_name;
};

} // namespace vrkit
#endif  // _VRKIT_AUDIO_H_
