#ifndef __PAREN_TEST_HPP__
#define __PAREN_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/paren.hpp"
#include "../headers/op.hpp"


TEST(ParenTest, DiffOps) {
    Op* value1 = new Op(5);
    Op* value2 = new Op(7);
    Op* value3 = new Op(4);
    Sub* min = new Sub(value2, value3);

    Paren* exp = new Paren(min);
    Add* test = new Add(value1, exp);

   // EXPECT_EQ(test->evaluate(), );
    EXPECT_EQ(test->stringify(), "5.000000 + (7.000000 - 4.000000)");
}

TEST(ParenTest, SingleOp) {
    Op* value1 = new Op(3);
    Op* value2 = new Op(6);

    Mult* exp = new Mult(value1, value2);
    Paren* test = new Paren(exp);

    EXPECT_EQ(test->stringify(), "(3.000000 * 6.000000)");
}


#endif
