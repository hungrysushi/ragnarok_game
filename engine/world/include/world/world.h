#pragma once

#include "util/vec_types.h"

namespace Ragnarok {
class World {
public:
        World();
        ~World();
        
        /* get the size of the world */
        vec3 GetDimensions();
        
        /* current view position */
        vec3 GetView();

protected:
        const vec3 dimensions_;
        vec3 view_;
};

}  // namespace Ragnarok
