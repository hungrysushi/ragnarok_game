#include "audio/openal_source.h"
#include "audio/openal_util.h"

namespace Ragnarok {
    
Source::Source() {
    alGenSources(1, &sourceId_);
    /* checkALError("Couldn't create source"); */
}

Source::~Source() {
    stop();
    alDeleteSources(1, &sourceId_);
}

void Source::setPosition(const vec3<float> position) {
    alSource3f(sourceId_, AL_POSITION, position.x, position.y, position.z);
    position_ = position;
}

void Source::setVelocity(const vec3<float> velocity) {
    alSource3f(sourceId_, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
} 

void Source::setDirection(const vec3<float> direction) {
    alSource3f(sourceId_, AL_DIRECTION, direction.x, direction.y, direction.z);
}

void Source::setVolume(const float volume) {
    alSourcef(sourceId_, AL_GAIN, volume);
    volume_ = volume;
}

void Source::setPitch(const float pitch) {
    alSourcef(sourceId_, AL_GAIN, pitch);
    pitch_ = pitch;
}

void Source::setLoop(bool loop) {
    alSourcei(sourceId_, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
}

void Source::play() {
    //TODO:set up buffer mechanism
    //stream? seek capabilities?
}

void Source::pause() {
    alSourcePause(sourceId_);
}

bool Source::isPlaying() {
    ALenum state;
    alGetSourcei(sourceId_, AL_SOURCE_STATE, &state);

    return (state == AL_PLAYING);
}

void Source::stop() {
    alSourceStop(sourceId_);
}


float Source::getVolume() {
    return volume_;
}

float Source::getPitch() {
    return pitch_;
}

vec3<float> Source::getPosition() {
    return position_;
}

}  // namespace Ragnarok
