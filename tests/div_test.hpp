#ifndef _DIV_TEST_HPP_
#define _DIV_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/div.hpp"

TEST(DivTest, DivBase) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(2);

	Div* test = new Div(value1, value2);

	EXPECT_EQ(test->evaluate(), 1);
	EXPECT_EQ(test->stringify(), "2.000000 / 2.000000");
}

TEST(DivTest, DivZero) {
	Op* value1 = new Op(0);
	Op* value2 = new Op(2);

	Div* test = new Div(value1, value2);

	EXPECT_EQ(test->evaluate(), 0);
	EXPECT_EQ(test->stringify(), "0.000000 / 2.000000");
}

TEST(DivTest, DivNegative) {
	Op* value1 = new Op(-2);
	Op* value2 = new Op(1);

	Div* test = new Div(value1, value2);

	EXPECT_EQ(test->evaluate(), -2);
	EXPECT_EQ(test->stringify(), "-2.000000 / 1.000000");
}

#endif
