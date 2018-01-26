#include "listener/listener.h"

namespace OpenAL {

        Listener::Listener();
        
        void Listener::setPosition(float x, float y, float z); 

        void Listener::setVelocity(float x, float y, float z); 
        
        void Listener::setDirection(float x, float y, float z);

        void Listener::setVolume(float volume);
        
        float Listener::getVolume();

        /* someObject Listener::getPosition(); */

        Listener::~Listener();

}
