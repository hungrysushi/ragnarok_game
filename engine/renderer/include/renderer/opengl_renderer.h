#pragma once

#include "renderer/renderer.h"

namespace Ragnarok {

class OpenGLRenderer : public Renderer {
public:
        OpenGLRenderer();
        ~OpenGLRenderer();
        
        void DrawWorld(/*World world*/);
};

}  // namespace Ragnarok
