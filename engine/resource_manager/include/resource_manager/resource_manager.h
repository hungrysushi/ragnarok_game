#pragma once

#include "resource_manager/types.h"

namespace Ragnarok {

class ResourceManager {
public:
        ResourceManager() { }
        virtual ~ResourceManager() { }

        /**
         * Allocate a pointer of the size requested, or store an already
         * allocated pointer along with a deallocator function
         */
        virtual void Allocate(VoidPtr& target, const uint32_t allocate_size) = 0;

        /**
         * Save a pointer and a deallocator closure so that we can still track
         * it from a single point
         */
        virtual void Track(VoidPtr& target, const Deallocator& deallocate) = 0;

        /**
         * Delete/recycle the memory used by the target pointer
         */
        virtual void Deallocate(VoidPtr& target, const ResourceType type) = 0;

        /**
         * Return the amount of memory in use
         */
        virtual uint32_t Size() = 0;

        /**
         * Return the amount of available space when we have a reserved pool
         */
        virtual uint32_t Capacity() = 0;
};

}  // namespace Ragnarok
