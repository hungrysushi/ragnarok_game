#pragma once

#include <AL/al.h>
#include "util/vec_types.h"

namespace Ragnarok {

class Listener {

public:
    void setPosition(const vec3<float> position); 

    void setVelocity(const vec3<float> velocity); 
    
    void setOrientation(const vec3<float> at, const vec3<float> up);

    void setVolume(const float volume);
    
    float getVolume();

    vec3<float> getPosition(); 

    vec3<float> getVelocity(); 

private:
    float volume_;
    vec3<float> position_;
    vec3<float> velocity_;
   
};

}  // namespace Ragnarok
