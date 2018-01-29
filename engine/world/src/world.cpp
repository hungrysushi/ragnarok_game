
#include "world/world.h"

namespace Ragnarok {

World::World() {
        // TODO
}

World::~World() {
        // TODO
}

vec3<float> World::GetDimensions() {
        // include levelTag as parameter?
        return dimensions_;
}

vec3<float> World::GetView() {
        return view_;
}

void World::GetLevelTag() {
        // TODO
}

void World::ReadLevelData(FILE** worldEntityData) {
        //TODO
}

}  // namespace Ragnarok
