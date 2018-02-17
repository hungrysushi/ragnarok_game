
#include "resource_manager/speedy_allocator.h"

namespace Ragnarok {

SpeedyAllocator::SpeedyAllocator() {
        // TODO
}

SpeedyAllocator::~SpeedyAllocator() {
        // TODO
}

void SpeedyAllocator::Allocate(VoidPtr& target, const uint32_t allocate_size) {

        target = (VoidPtr) new uint8_t[allocate_size];

        // save the pointer in a map. This is definitely not space efficient,
        // but it'll make things somewhat quick
        dispersed_map_[(uint8_t*) target] = allocate_size;
}

void SpeedyAllocator::Track(VoidPtr& target, const Deallocator& deallocator) {
        // keep track of something allocated outside
        unmanaged_map_[(uint8_t*) target] = deallocator;
}

void SpeedyAllocator::Deallocate(VoidPtr& target, const ResourceType type) {

        if (type == ResourceType::kDispersed || type == ResourceType::kPacked) {
                // delete the pointer from our map
                dispersed_map_.erase((uint8_t*) target);

                // don't care about space reuse
                delete[] (uint8_t*) target;
        }
        else if (type == ResourceType::kUnmanaged) {
                // call the closure for freeing up this resource
                unmanaged_map_[target].deallocate();

                // delete from our map
                unmanaged_map_.erase((uint8_t*) target);
        }

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
