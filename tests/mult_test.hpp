#ifndef _MULT_TEST_HPP_
#define _MULT_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/mult.hpp"

TEST(MultTest, MultBase) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(2);

	Mult* test = new Mult(value1, value2);

	EXPECT_EQ(test->evaluate(), 4);
	EXPECT_EQ(test->stringify(), "2.000000 * 2.000000");
}

TEST(MultTest, MultZero) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(0);

	Mult* test = new Mult(value1, value2);

	EXPECT_EQ(test->evaluate(), 0);
	EXPECT_EQ(test->stringify(), "2.000000 * 0.000000");
}

TEST(MultTest, MultNegative) {
	Op* value1 = new Op(-2);
	Op* value2 = new Op(1);

	Mult* test = new Mult(value1, value2);

	EXPECT_EQ(test->evaluate(), -2);
	EXPECT_EQ(test->stringify(), "-2.000000 * 1.000000");
}

#endif

