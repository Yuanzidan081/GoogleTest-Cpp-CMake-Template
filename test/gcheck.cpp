#include <gtest/gtest.h>

// add your test function header file
#include "function/TestFunction.h"

TEST(HelloTest, ADD)
{
    EXPECT_EQ(5, add(2, 3));
}

TEST(HelloTest, SUB)
{

    EXPECT_EQ(2, sub(5, 3));
}
