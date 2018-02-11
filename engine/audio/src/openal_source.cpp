#include "audio/openal_source.h"
#include "audio/openal_util.h"

namespace Ragnarok {
    
Source::Source() {
    alGenSources(1, &sourceId_);
    /* checkALError("Couldn't create source"); */
}

Source::~Source() {
    Stop();
    alDeleteSources(1, &sourceId_);
}

void Source::SetPosition(const vec3<float> position) {
    alSource3f(sourceId_, AL_POSITION, position.x, position.y, position.z);
    position_ = position;
}

void Source::SetVelocity(const vec3<float> velocity) {
    alSource3f(sourceId_, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
} 

void Source::SetDirection(const vec3<float> direction) {
    alSource3f(sourceId_, AL_DIRECTION, direction.x, direction.y, direction.z);
}

void Source::SetVolume(const float volume) {
    alSourcef(sourceId_, AL_GAIN, volume);
    volume_ = volume;
}

void Source::SetPitch(const float pitch) {
    alSourcef(sourceId_, AL_GAIN, pitch);
    pitch_ = pitch;
}

void Source::SetLoop(bool loop) {
    alSourcei(sourceId_, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
}

void Source::Play() {
    //TODO:set up buffer mechanism
    //stream? seek capabilities?
}

void Source::Pause() {
    alSourcePause(sourceId_);
}

bool Source::IsPlaying() {
    ALenum state;
    alGetSourcei(sourceId_, AL_SOURCE_STATE, &state);

    return (state == AL_PLAYING);
}

void Source::Stop() {
    alSourceStop(sourceId_);
}


float Source::GetVolume() {
    return volume_;
}

float Source::GetPitch() {
    return pitch_;
}

vec3<float> Source::GetPosition() {
    return position_;
}

}  // namespace Ragnarok
