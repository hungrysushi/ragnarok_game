#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>

void CheckALError(const char* operation) {

    ALenum alErr = alGetError();
    if(alErr == AL_NO_ERROR) return;

    std::string op(operation);

    switch(alErr) {
        case AL_INVALID_NAME:
            std::cout << "OpenALError: " + op + " (AL_INVALID_NAME)" << std::endl;
            break;
        case AL_INVALID_VALUE:
            std::cout << "OpenALError: " + op + " (AL_INVALID_VALUE)" << std::endl;
            break;
        case AL_INVALID_ENUM:
            std::cout << "OpenALError: " + op + " (AL_INVALID_ENUM)" << std::endl;
            break;
        case AL_OUT_OF_MEMORY:
            std::cout << "OpenALError: " + op + " (AL_OUT_OF_MEMORY)" << std::endl;
            break;
        case AL_INVALID_OPERATION:
            std::cout << "OpenALError: " + op + " (AL_INVALID_OPERATION)" << std::endl;
            break;
    }

} 

ALenum getALFormat(unsigned int channels) {

    switch(channels) {

        case 1: return AL_FORMAT_MONO16;
        case 2: return AL_FORMAT_STEREO16;
        case 4: return alGetEnumValue("AL_FORMAT_QUAD16");
        case 6: return alGetEnumValue("AL_FORMAT_51CHN16");
        case 7: return alGetEnumValue("AL_FORMAT_61CHN16");
        case 8: return alGetEnumValue("AL_FORMAT_71CHN16");

        default: return 0;

    }
}
