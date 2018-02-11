#include "audio/openal_device.h"
#include "audio/openal_util.h"

namespace Ragnarok {

Device::Device() 
    : context_(nullptr), playbackDevice_(nullptr) {
    alcMakeContextCurrent(nullptr);
    playbackDevice_ = alcOpenDevice(nullptr);
    CheckALError("Couldn't create audio device");
    context_ = alcCreateContext(playbackDevice_, nullptr);
    alcMakeContextCurrent(context_);
}

Device::~Device() {
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context_);
    alcCloseDevice(playbackDevice_);
}

}  // namespace Ragnarok
