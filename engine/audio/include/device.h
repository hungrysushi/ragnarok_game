#pragma once

/* #include <AL/al.h> */
/* #include <AL/alc.h> */

namespace Ragnarok {

class Device {
    
public:
    Device();

    ~Device();

    void changePlaybackDevice(const ALChar *deviceName);

    void changeCaptureDevice(const ALChar *deviceName);

private:
    ALCDevice *m_PlaybackDevice;
    ALCDevice *m_CaptureDevice;
    ALCContext *m_Context;

}
