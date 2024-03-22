#include <gtest/gtest.h>
#include <stdexcept>
#include "stack.hpp"

using namespace stack;

TEST(stack, methods) {
    Stack<int> stack;
    stack.push(123);
    EXPECT_EQ(stack.top(), 123);
    stack.push(12);
    EXPECT_EQ(stack.top(), 12);
    stack.pop();
    EXPECT_EQ(stack.top(), 123);
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
    for (int i = 0; i < 10; ++i)
        stack.push(i);
    EXPECT_EQ(stack.size(), 10);
    stack.clear();
    EXPECT_TRUE(stack.is_empty());
}

TEST(stack, constructors) {
    Stack<int> stack1;
    stack1.push(123);
    Stack<int> stack2(stack1);
    Stack<int> stack2_ = stack1;
    stack2.push(11);
    stack2_.push(11);
    EXPECT_EQ(stack1.top(), 123);
    EXPECT_EQ(stack2.top(), 11);
    EXPECT_EQ(stack2_.top(), 11);
    Stack<int> stack3(std::move(stack2));
    Stack<int> stack3_ = std::move(stack1);
    EXPECT_THROW(stack2.top(), std::out_of_range);
    EXPECT_THROW(stack1.top(), std::out_of_range);
    EXPECT_EQ(stack3.top(), 11);
    EXPECT_EQ(stack3_.top(), 123);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}