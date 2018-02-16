#pragma once

namespace Ragnarok {

enum ResourceType {
        kUnmanaged,  // actual placement of this doesn't matter
        kPacked,  // these should be placed close together in memory
};

}  // namespace Ragnarok
