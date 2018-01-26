#pragma once

/* #include <AL/al.h> */
/* #include <AL/alc.h> */

namespace OpenAL {

class Device {
    
    private:
        ALCDevice *m_PlaybackDevice;
        ALCDevice *m_CaptureDevice;
        ALCContext *m_Context;
        
    public:
        Device();
        
        void changePlaybackDevice(const ALChar *deviceName);

        void changeCaptureDevice(const ALChar *deviceName);

        ~Device();

}
