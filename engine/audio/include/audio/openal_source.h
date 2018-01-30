#pragma once

#include <AL/al.h>

namespace Ragnarok {

class Source {

public:
    Source();
    
    ~Source();
    
    //TODO: Put (x, y, z) in a struct

    void setPosition(const float x, const float y, const float z); 

    void setVelocity(const float x, const float y, const float z); 
    
    void setDirection(const float x, const float y, const float z);

    void setVolume(float const volume);

    float getVolume();

    /* someObject getPosition(); */
    
    /* someObject getStatus(); */


private:
    int m_sourceId;
    float m_currentVolume;
    /* someObject m_position; */

};

}  // namespace Ragnarok
