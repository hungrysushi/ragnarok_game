#include "audio/openal_listener.h"

namespace Ragnarok {

void Listener::setPosition(const vec3<float> position) {
    alListener3f(AL_POSITION, position.x, position.y, position.z);
    position_ = position;
} 

void Listener::setVelocity(const vec3<float> velocity) {
    alListener3f(AL_VELOCITY, velocity.x, velocity.y, velocity.z);
    velocity_ = velocity;
}

void Listener::setOrientation(const vec3<float> at, const vec3<float> up) {
    float orientation[] = {
        at.x,
        at.y,
        at.z,
        up.x,
        up.y,
        up.z
    }; 
}

void Listener::setVolume(const float volume) {
   alListenerf(AL_GAIN, volume);
   volume_ = volume;
}

float Listener::getVolume() {
    return volume_;
}

vec3<float> Listener::getPosition() {
    return position_;
}

vec3<float> Listener::getVelocity() {
    return velocity_;
}

}  // namespace Ragnarok
