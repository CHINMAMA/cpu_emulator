#include <gtest/gtest.h>
#include <stdexcept>
#include "stack.hpp"

using namespace stack;

TEST(test, test) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}