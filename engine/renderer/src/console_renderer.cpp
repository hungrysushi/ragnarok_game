#include "renderer/console_renderer.h"

#include <iostream>

namespace Ragnarok {

ConsoleRenderer::ConsoleRenderer() {
        // nothing to set up here
}

ConsoleRenderer::~ConsoleRenderer() {
        // Nothing to do
}

void ConsoleRenderer::DrawWorld(World world) {
        std::cout << world.GetDimensions() << "\n";
        std::cout << world.GetView() << std::endl;

        // TODO when the world has entities, iterate over them and print
}

}  // namespace Ragnarok
