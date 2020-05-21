#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/sub.hpp"
#include "../headers/add.hpp"
#include "../headers/mult.hpp"
#include "../headers/ListContainer.hpp"

TEST(ListContainerTestSet, SwapElementTest) {
    //Setup the elements under test

    Op* seven 	= new Op(7);
    Op* one 	= new Op(1);
    Op* four 	= new Op(4);
    ListContainer* test_container = new ListContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    test_container->add_element(one);
    test_container->add_element(four);

    // Assert that the container has at least a single element
    ASSERT_EQ(test_container->size(), 3);

    test_container->swap(0,1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
}

TEST(ListContainerTestSet, AddElementTest) {
    //Setup the elements under test

    Op* seven 	= new Op(7);
    Op* one 	= new Op(1);
    Op* four 	= new Op(4);
    ListContainer* test_container = new ListContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    test_container->add_element(one);
    test_container->add_element(four);

    // Assert that the container has at least a single element
    ASSERT_EQ(test_container->size(), 3);

    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 1);
    EXPECT_EQ(test_container->at(2)->evaluate(), 4);
}

/*TEST(ListContainerTestSet, PrintList){
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Op* three = new Op(3);
	ListContainer* test_container = new ListContainer();
	
	test_container->add_element(seven);
	test_container->add_element(four);
	test_container->add_element(three);
	
	test_container->print();
	
	ASSERT_EQ(test_container->size(), 3);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	EXPECT_EQ(test_container->at(1)->evaluate(), 4);
	EXPECT_EQ(test_container->at(2)->evaluate(), 3);
}

TEST(ListContainerTestSet, PrintTrees){
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Mult* TreeA = new Mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	Add* TreeB = new Add(three, two);

	Op* ten = new Op(10);
	Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);

	ListContainer* test_container = new ListContainer();
	test_container->add_element(TreeA);
	test_container->add_element(TreeB);
	test_container->add_element(TreeC);	
	
	test_container->print();
	ASSERT_EQ(test_container->size(), 3);
	EXPECT_EQ(test_container->at(0)->evaluate(), 28);
	EXPECT_EQ(test_container->at(1)->evaluate(), 5);
	EXPECT_EQ(test_container->at(2)->evaluate(), 4);
}*/
#endif
