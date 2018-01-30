#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

namespace Ragnarok {

class Device {
    
public:
    Device();

    ~Device();

    void changePlaybackDevice(const ALchar *deviceName);

    void changeCaptureDevice(const ALchar *deviceName);

private:
    ALCdevice *m_PlaybackDevice;
    ALCdevice *m_CaptureDevice;
    ALCcontext *m_Context;

};

}  // namespace Ragnarok
