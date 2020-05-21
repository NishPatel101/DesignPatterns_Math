#ifndef __ABS_TEST_HPP__
#define __ABS_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/abs.hpp"

TEST(AbsoluteTest, NegativeValue) {
    Op* value1 = new Op(-3.7);
    Op* value2 = new Op(-3.1);

    Abs* test = new Abs(value1);
    Abs* test2 = new Abs(value2);

    EXPECT_EQ(test->evaluate(), 3.7);
    EXPECT_EQ(test2->evaluate(),3.1);
}

TEST(AbsoluteTest, PositiveValue) {
    Op* value1 = new Op(5.9);
    Op* value2 = new Op(5.2);

    Abs* test = new Abs(value1);
    Abs* test2 = new Abs(value2);

    EXPECT_EQ(test->evaluate(), 5.9);
    EXPECT_EQ(test2->evaluate(),5.2);
}

#endif //__ABS_TEST_HPP__
