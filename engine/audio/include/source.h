#pragma once

/* #include <AL/al.h> */

namespace Ragnarok {

class Source {

public:
    Source();
    
    //TODO: Put (x, y, z) in a struct

    void setPosition(float x, float y, float z); 

    void setVelocity(float x, float y, float z); 
    
    void setDirection(float x, float y, float z);

    void setVolume(float volume);

    float getVolume();

    /* someObject getPosition(); */
    
    /* someObject getStatus(); */

    ~Source();

private:
    int m_sourceId;
    float m_currentVolume;
    /* someObject m_position; */

}
