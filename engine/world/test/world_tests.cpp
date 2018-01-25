
#include "world/world.h"

#include <gtest/gtest.h>

#include "util/vec_types.h"

namespace Ragnarok {

class WorldTests : public ::testing::Test {
public:
        WorldTests() {

        }

        virtual ~WorldTests() {

        }

        virtual void SetUp() {

        }

        virtual void TearDown() {

        }

        World world_;
};

TEST_F(WorldTests, dimensions_initial) {
        vec3 vector = {0.0, 0.0, 0.0};
        EXPECT_EQ(vector, world_.Dimensions());
}

TEST_F(WorldTests, view_initial) {
        vec3 vector = {0.0, 0.0, 0.0};
        EXPECT_EQ(vector, world_.View());
}

}  // namespace Ragnarok