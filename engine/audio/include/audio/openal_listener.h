#pragma once

#include <AL/al.h>
#include "util/vec_types.h"

namespace Ragnarok {

class Listener {

public:
    Listener();
    
    ~Listener(); 
    
    void setPosition(const vec3<float> position); 

    void setVelocity(const vec3<float> velocity); 
    
    void setDirection(const vec3<float> direction);

    void setVolume(const float volume);
    
    float getVolume();

    vec3<float> getPosition(); 

private:
    float volume_;
   
};

}  // namespace Ragnarok
