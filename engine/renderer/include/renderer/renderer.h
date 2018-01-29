#pragma once

namespace Ragnarok {

class Renderer {
public:
        Renderer() {}
        virtual ~Renderer() {}

        virtual void DrawWorld(/*World world*/) = 0;
};

}  // namespace Ragnarok
