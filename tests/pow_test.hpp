#ifndef _POW_TEST_HPP_
#define _POW_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/pow.hpp"

TEST(PowTest, PowBase) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(2);

	Pow* test = new Pow(value1, value2);

	EXPECT_EQ(test->evaluate(), 4);
	EXPECT_EQ(test->stringify(), "2.000000 ** 2.000000");
}

TEST(PowTest, PowZero) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(0);

	Pow* test = new Pow(value1, value2);

	EXPECT_EQ(test->evaluate(), 1);
	EXPECT_EQ(test->stringify(), "2.000000 ** 0.000000");
}

TEST(PowTest, PowNegative) {
	Op* value1 = new Op(-2);
	Op* value2 = new Op(1);

	Pow* test = new Pow(value1, value2);

	EXPECT_EQ(test->evaluate(), -2);
	EXPECT_EQ(test->stringify(), "-2.000000 ** 1.000000");
}

TEST(PowTest, PowDecimal) {
	Op* value1 = new Op(9);
	Op* value2 = new Op(0.5);

	Pow* test = new Pow(value1, value2);

	EXPECT_EQ(test->evaluate(), 3);
	EXPECT_EQ(test->stringify(), "9.000000 ** 0.500000");
}

#endif
