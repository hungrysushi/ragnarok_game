
#include "resource_manager/speedy_allocator.h"

#include <gtest/gtest.h>

using namespace Ragnarok;

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

TEST_F(SpeedyAllocatorTests, allocate_and_deallocate) {
        TestClass *test_class = nullptr;

        allocator_.Allocate((void*&) test_class, sizeof(TestClass));
        EXPECT_NE(test_class, nullptr);

        test_class->Init();
        EXPECT_EQ(test_class->member_1_, 0);
        EXPECT_EQ(test_class->member_2_, 1);

        allocator_.Deallocate((void*&) test_class, Ragnarok::ResourceType::kDispersed);
        EXPECT_EQ(test_class, nullptr);
}

TEST_F(SpeedyAllocatorTests, track_and_deallocate) {
        TestClass *test_class = new TestClass();

        Deallocator deallocator = {
                [&](){
                        delete test_class;
                },
                sizeof(TestClass)
        };
        allocator_.Track((void*&) test_class, deallocator);

        allocator_.Deallocate((void*&) test_class, ResourceType::kUnmanaged);
        EXPECT_EQ(test_class, nullptr);
}


}
