#pragma once

#include <functional>

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

/**
 * Hold data relevant to pointers allocated outside of the allocator
 */
struct Deallocator {
        // a closure that should use the external mechanism for freeing an unmanaged resource
        std::function<void()> deallocate;

        // size of item, if available
        uint32_t size = 0;
};

}  // namespace Ragnarok
