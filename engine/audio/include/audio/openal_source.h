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

    float getVolume();

    /* someObject getPosition(); */
    
    /* someObject getStatus(); */


private:
    int m_sourceId;
    float m_currentVolume;
    /* someObject m_position; */

};

}  // namespace Ragnarok
