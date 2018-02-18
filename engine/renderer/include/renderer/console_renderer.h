#pragma once

#include "renderer/renderer.h"
#include "world/world.h"

namespace Ragnarok {

class ConsoleRenderer : public Renderer {
public:
        ConsoleRenderer();
        ~ConsoleRenderer();

        void DrawWorld(World world);
};

}  // namespace Ragnarok
