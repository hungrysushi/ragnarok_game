
#include <iostream>
#include <memory>

#include "renderer/renderer.h"
#include "renderer/opengl_renderer.h"
#include "renderer/console_renderer.h"

int main(int argc, char** argv)
{
        std::cout << "Starting game\n";

        // TODO have this returned by a factory, or maybe surround with ifdefs
        // for specific implementations
        std::shared_ptr<Ragnarok::Renderer> renderer;

#ifdef RENDER_CONSOLE
        renderer = std::make_shared<Ragnarok::ConsoleRenderer>();
#endif
        
#ifdef RENDER_OPENGL
        renderer = std::make_shared<Ragnarok::OpenGLRenderer>();
#endif

        if (!renderer) {
                std::cout << "Failed to create renderer, or correct macros not defined" << std::endl;
        }

        return 0;
}
