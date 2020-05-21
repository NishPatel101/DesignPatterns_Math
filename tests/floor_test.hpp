#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/floor.hpp"
#include "../headers/op.hpp"

TEST(FloorTest, Round) {
    Op* value1 = new Op(5.3);
    Op* value2 = new Op(5.8);

    Floor* test = new Floor(value1);
    Floor* test2 = new Floor(value2);

    EXPECT_EQ(test->evaluate(), 5);
    EXPECT_EQ(test2->evaluate(),5);
}

TEST(FloorTest, Zero) {
    Op* value1 = new Op(0.1);
    Op* value2 = new Op(0.6);

    Floor* test = new Floor(value1);
    Floor* test2 = new Floor(value2);

    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test2->evaluate(),0);
}

#endif //__FLOOR_TEST_HPP__
