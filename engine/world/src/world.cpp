
#include "world/world.h"

namespace Ragnarok {

World::World() {
        // TODO
}

World::~World() {
        // TODO
}

vec3<float> World::GetDimensions() {
        return dimensions_;
}

vec3<float> World::GetView() {
        return view_;
}

}  // namespace Ragnarok
