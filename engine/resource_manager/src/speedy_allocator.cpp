
#include "resource_manager/speedy_allocator.h"

namespace Ragnarok {

SpeedyAllocator::SpeedyAllocator() {
        // TODO
}

SpeedyAllocator::~SpeedyAllocator() {
        // TODO
}

VoidPtr SpeedyAllocator::Allocate(const uint32_t allocate_size, const ResourceType type) {

        uint8_t *target = new uint8_t[allocate_size];

        // save the pointer in a map. This is definitely not space efficient,
        // but it'll make things somewhat quick
        unmanaged_map_[target] = allocate_size;
        
        return (VoidPtr) target;
}

void SpeedyAllocator::Deallocate(VoidPtr& target, const ResourceType type) {

        // delete the pointer from our map
        unmanaged_map_.erase((uint8_t*) target);

        // don't care about space reuse
        delete[] (uint8_t*) target;

        target = nullptr;
}

uint32_t SpeedyAllocator::Size() {
        // TODO iterate over map and get the total size
        return 0;
}

uint32_t SpeedyAllocator::Capacity() {
        // TODO in this implementation, this is identical to size
        return 0;
}

}  // namespace Ragnarok
