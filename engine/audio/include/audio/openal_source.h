#pragma once

#include <AL/al.h>
#include "util/vec_types.h"

namespace Ragnarok {

class Source {

public:
    Source();
    
    ~Source();

    void setPosition(const vec3<float> position); 

    void setVelocity(const vec3<float> velocity); 
    
    void setDirection(const vec3<float> direction);

    void setVolume(const float volume);

    void setPitch(const float pitch);

    void setLoop(bool loop);

    void play();

    void pause();

    bool isPlaying();

    void stop();

    float getVolume();

    float getPitch();

    vec3<float> getPosition();

private:
    ALuint sourceId_;
    float volume_;
    float pitch_;
    vec3<float> position_;

};

}  // namespace Ragnarok
