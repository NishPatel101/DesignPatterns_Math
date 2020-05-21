#ifndef _SUB_TEST_HPP_
#define _SUB_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/sub.hpp"

TEST(SubTest, SubBase) {
	Op* value1 = new Op(3);
	Op* value2 = new Op(2);

	Sub* test = new Sub(value1, value2);

	EXPECT_EQ(test->evaluate(), 1);
	EXPECT_EQ(test->stringify(), "3.000000 - 2.000000");
}

TEST(SubTest, SubZero) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(0);

	Sub* test = new Sub(value1, value2);

	EXPECT_EQ(test->evaluate(), 2);
	EXPECT_EQ(test->stringify(), "2.000000 - 0.000000");
}

TEST(SubTest, SubNegative) {
	Op* value1 = new Op(-2);
	Op* value2 = new Op(1);

	Sub* test = new Sub(value1, value2);

	EXPECT_EQ(test->evaluate(), -3);
	EXPECT_EQ(test->stringify(), "-2.000000 - 1.000000");
}

#endif
