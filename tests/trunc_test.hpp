#ifndef __TRUNC_TEST_HPP__
#define __TRUNC_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/trunc.hpp"
#include "../headers/op.hpp"


TEST(TruncTest, DiffOps) {
    Op* value1 = new Op(5);
    Op* value2 = new Op(7);
    Op* value3 = new Op(4);
    Sub* min = new Sub(value2, value3);

    Trunc* exp = new Trunc(min);
    Add* test = new Add(value1, exp);

   // EXPECT_EQ(test->evaluate(), 4);
    EXPECT_EQ(test->stringify(), "5.000000 + 3.000000");
}

TEST(TruncTest, SingleOp) {
    Op* value1 = new Op(3);
    Op* value2 = new Op(6);

    Div* div = new Div(value2, value1);
    Trunc* test = new Trunc(div);

    EXPECT_EQ(test->evaluate(), 2.000000);
    EXPECT_EQ(test->stringify(), "2.000000");
}


#endif
