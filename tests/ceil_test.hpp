#ifndef __CEIL_TEST_HPP__
#define __CEIL_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/ceil.hpp"
#include "../headers/op.hpp"

TEST(CeilTest, Round) {
    Op* value1 = new Op(3.1);
    Op* value2 = new Op(3.6);

    Ceil* test = new Ceil(value1);
    Ceil* test2 = new Ceil(value2);

    EXPECT_EQ(test->evaluate(), 4);
    EXPECT_EQ(test2->evaluate(), 4);
}

TEST(CeilTest, Zero) {
    Op* value1 = new Op(0.1);
    Op* value2 = new Op(0.6);

    Ceil* test = new Ceil(value1);
    Ceil* test2 = new Ceil(value2);

    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test2->evaluate(), 1);
}


#endif //__CEIL_TEST_HPP__
