#pragma once

#include "util/vec_types.h"

namespace Ragnarok {
class World {
public:
        World();
        ~World();
        
        /* get the size of the world */
        vec3<float> GetDimensions();
        
        /* current view position */
        vec3<float> GetView();

protected:
        const vec3<float> dimensions_;
        vec3<float> view_;
};

}  // namespace Ragnarok
