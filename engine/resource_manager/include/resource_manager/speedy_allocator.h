#pragma once

#include <map>

#include "resource_manager/resource_manager.h"
#include "resource_manager/types.h"

namespace Ragnarok {

/**
 * This class is just to provide fast allocations with a single point of
 * failure to debug. It is aware of how much memory has been allocated, but
 * the focus is not on managing space efficiently
 */
class SpeedyAllocator : public ResourceManager {
public:
        SpeedyAllocator();
        ~SpeedyAllocator();

        void Allocate(VoidPtr& target, const uint32_t allocate_size, const ResourceType type, const Deallocator& deallocator);
        void Deallocate(VoidPtr& target, const ResourceType type);
        uint32_t Size();
        uint32_t Capacity();

        std::map<uint8_t*, uint32_t> dispersed_map_;
        std::map<VoidPtr, Deallocator> unmanaged_map_;
};

}  // namespace Ragnarok
