
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

        // add the allocated size to the total
        size_ += allocate_size;
}

void SpeedyAllocator::Track(VoidPtr& target, const Deallocator& deallocator) {
        // keep track of something allocated outside
        unmanaged_map_[(uint8_t*) target] = deallocator;

        // add this objects size to the total
        size_ += deallocator.size;
}

void SpeedyAllocator::Deallocate(VoidPtr& target, const ResourceType type) {

        if (type == ResourceType::kDispersed || type == ResourceType::kPacked) {
                // update the size
                size_ -= dispersed_map_[(uint8_t*) target];

                // delete the pointer from our map
                dispersed_map_.erase((uint8_t*) target);

                // don't care about space reuse
                delete[] (uint8_t*) target;
        }
        else if (type == ResourceType::kUnmanaged) {
                // update the size
                size_ -= unmanaged_map_[target].size;

                // call the closure for freeing up this resource
                unmanaged_map_[target].deallocate();

                // delete from our map
                unmanaged_map_.erase((uint8_t*) target);
        }

        target = nullptr;
}

uint32_t SpeedyAllocator::Size() {
        return size_;
}

uint32_t SpeedyAllocator::Capacity() {
        // in this implementation, this is identical to size
        return Size();
}

}  // namespace Ragnarok
