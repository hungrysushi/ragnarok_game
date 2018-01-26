#pragma once

/* #include <AL/al.h> */

namespace OpenAL {

class Listener {
    private:
        float m_currentVolume;

    public:
        Listener();
        
        //TODO: Put (x, y, z) in a struct instead

        void setPosition(float x, float y, float z); 

        void setVelocity(float x, float y, float z); 
        
        void setDirection(float x, float y, float z);

        void setVolume(float volume);
        
        float getVolume();

        /* someObject getPosition(); */

        ~Listener(); 
        
};

}
