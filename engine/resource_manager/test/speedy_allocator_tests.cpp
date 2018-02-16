
#include "resource_manager/speedy_allocator.h"

#include <gtest/gtest.h>

namespace {

class SpeedyAllocatorTests : public ::testing::Test {
public:
        SpeedyAllocatorTests() {

        }

        Ragnarok::SpeedyAllocator allocator_;                
};

class TestClass {
public:
        TestClass() {

        }
        ~TestClass() {

        }

        void Init() {
                member_1_ = 0;
                member_2_ = 1;
        }

        int member_1_;
        int member_2_;
};

TEST_F(SpeedyAllocatorTests, allocate) {
        TestClass* test_class = (TestClass*) allocator_.Allocate(sizeof(TestClass), Ragnarok::ResourceType::kUnmanaged);

        test_class->Init();
        
        EXPECT_EQ(test_class->member_1_, 0);
        EXPECT_EQ(test_class->member_2_, 1);
}

TEST_F(SpeedyAllocatorTests, deallocate) {
        TestClass* test_class = (TestClass*) allocator_.Allocate(sizeof(TestClass), Ragnarok::ResourceType::kUnmanaged);

        EXPECT_NE(test_class, nullptr);

        allocator_.Deallocate((void*&) test_class, Ragnarok::ResourceType::kUnmanaged);

        EXPECT_EQ(test_class, nullptr);
}


}
