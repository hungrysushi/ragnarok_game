#pragma once

namespace Ragnarok {

enum ResourceType {
        kUnmanaged,  // these are allocated outside and are freed by some other mechanism
        kDispersed,  // actual placement of this doesn't matter
        kPacked,  // these should be placed close together in memory
};

/**
 * a more friendly alias for void pointers when using references
 */
typedef void* VoidPtr;

}  // namespace Ragnarok
