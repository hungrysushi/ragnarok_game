
#include <iostream>
#include <memory>

#include "renderer/renderer.h"
#include "renderer/opengl_renderer.h"

int main(int argc, char** argv)
{
        std::cout << "Starting game\n";

        // TODO have this returned by a factory, or maybe surround with ifdefs
        // for specific implementations
        std::shared_ptr<Ragnarok::Renderer> renderer = std::make_shared<Ragnarok::OpenGLRenderer>();

        return 0;
}
