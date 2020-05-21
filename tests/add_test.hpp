#ifndef _ADD_TEST_HPP_
#define _ADD_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/add.hpp"

TEST(AddTest, AddBase) {
	Op* value1 = new Op(1);
	Op* value2 = new Op(2);

	Add* test = new Add(value1, value2);

	EXPECT_EQ(test->evaluate(), 3.000000);
	EXPECT_EQ(test->stringify(), "1.000000 + 2.000000");
}

TEST(AddTest, AddZero) {
	Op* value1 = new Op(0);
	Op* value2 = new Op(0);

	Add* test = new Add(value1, value2);

	EXPECT_EQ(test->evaluate(), 0.000000);
	EXPECT_EQ(test->stringify(), "0.000000 + 0.000000");
}

TEST(AddTest, AddNegative) {
	Op* value1 = new Op(-2);
	Op* value2 = new Op(1);

	Add* test = new Add(value1, value2);

	EXPECT_EQ(test->evaluate(), -1.000000);
	EXPECT_EQ(test->stringify(), "-2.000000 + 1.000000");
}

#endif

