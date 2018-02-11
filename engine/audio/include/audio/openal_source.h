#pragma once

#include <AL/al.h>
#include "util/vec_types.h"

namespace Ragnarok {

class Source {

public:
    Source();
    
    ~Source();

    void SetPosition(const vec3<float> position); 

    void SetVelocity(const vec3<float> velocity); 
    
    void SetDirection(const vec3<float> direction);

    void SetVolume(const float volume);

    void SetPitch(const float pitch);

    void SetLoop(bool loop);

    void Play();

    void Pause();

    bool IsPlaying();

    void Stop();

    float GetVolume();

    float GetPitch();

    vec3<float> GetPosition();

private:
    ALuint sourceId_;
    float volume_;
    float pitch_;
    vec3<float> position_;

};

}  // namespace Ragnarok
