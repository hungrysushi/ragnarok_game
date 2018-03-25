#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include "audio/openal_device.h"

namespace Ragnarok {

class AudioManager {

public:
    AudioManager();
    
    ~AudioManager();

    void CreateSource(const std::string& name, const std::string& path, float volume, bool isLooping);

    void PlaySource();

    void PauseSource();

    void StopSource();

    void SetVolume();

    void CreateListener();

private:
    Device* device_;
    // name   -> (source, buffer) 
    // string -> (int, int)
    std::map<std::string, std::pair<ALuint, ALuint>> sources_;
}

} // namespace Ragnarok
