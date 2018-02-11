#include "audio/openal_listener.h"

namespace Ragnarok {

void Listener::SetPosition(const vec3<float> position) {
    alListener3f(AL_POSITION, position.x, position.y, position.z);
    position_ = position;
} 

void Listener::SetVelocity(const vec3<float> velocity) {
    alListener3f(AL_VELOCITY, velocity.x, velocity.y, velocity.z);
    velocity_ = velocity;
}

void Listener::SetOrientation(const vec3<float> at, const vec3<float> up) {
    float orientation[] = {
        at.x,
        at.y,
        at.z,
        up.x,
        up.y,
        up.z
    }; 
}

void Listener::SetVolume(const float volume) {
   alListenerf(AL_GAIN, volume);
   volume_ = volume;
}

float Listener::GetVolume() {
    return volume_;
}

vec3<float> Listener::GetPosition() {
    return position_;
}

vec3<float> Listener::GetVelocity() {
    return velocity_;
}

}  // namespace Ragnarok
