#pragma once

#include "resource_manager/types.h"

namespace Ragnarok {

class ResourceManager {
public:
        ResourceManager() { }
        virtual ~ResourceManager() { }

        /**
         * Return a pointer of the size requested
         */
        virtual VoidPtr Allocate(const uint32_t allocate_size, const ResourceType type) = 0;

        /**
         * Delete/recycle the memory used by the target pointer
         */
        virtual void Deallocate(VoidPtr& target, const ResourceType type) = 0;

        /**
         * Return the amount of memory in use
         */
        virtual uint32_t Size() = 0;

        /**
         * Return the amount of available space
         */
        virtual uint32_t Capacity() = 0;
};

}  // namespace Ragnarok
