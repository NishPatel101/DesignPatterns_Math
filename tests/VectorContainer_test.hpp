#ifndef _VECTORCONTAINER_TEST_HPP
#define _VECTORCONTAINER_TEST_HPP_

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/container.hpp"
#include "../headers/VectorContainer.hpp"

TEST(VectorTest, Empty) {
	VectorContainer* test = new VectorContainer();

	EXPECT_EQ(test->size(), 0);
}

TEST(VectorTest, SwapAtPrint) {
	Op* value1 = new Op(2);
	Op* value2 = new Op(1);
	Add* vals1 = new Add(value1, value2);

	Op* value3 = new Op(2);
	Op* value4 = new Op(1);
	Mult* vals2 = new Mult(value3, value4);

	VectorContainer* test = new VectorContainer();
	test->add_element(vals1);
	test->add_element(vals2);
	test->swap(0, 1);	

	EXPECT_EQ(test->at(0)->evaluate(), 2.000000);
}

#endif
