#pragma once

#include <AL/al.h>
#include "util/vec_types.h"

namespace Ragnarok {

class Listener {

public:
    void SetPosition(const vec3<float> position); 

    void SetVelocity(const vec3<float> velocity); 
    
    void SetOrientation(const vec3<float> at, const vec3<float> up);

    void SetVolume(const float volume);
    
    float GetVolume();

    vec3<float> GetPosition(); 

    vec3<float> GetVelocity(); 

private:
    float volume_;
    vec3<float> position_;
    vec3<float> velocity_;
   
};

}  // namespace Ragnarok
