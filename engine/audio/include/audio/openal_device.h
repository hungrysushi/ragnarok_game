#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

namespace Ragnarok {

class Device {
    
public:
    Device();

    ~Device();

private:
    ALCdevice *playbackDevice_;
    /* ALCdevice *captureDevice_; */
    ALCcontext *context_;

};

}  // namespace Ragnarok
