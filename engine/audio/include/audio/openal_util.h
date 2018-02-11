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

