#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "factory.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "binary_iterator.cpp"
#include "unary_iterator.cpp"
#include "preorder_iterator.cpp"
#include "decorator.hpp"
#include "ceil.hpp"

TEST(IteratorTest, UnaryTest){
    Base* threefive = new Op(3.5);
    Base* two = new Op(2);
    Base* add = new Add(threefive, two);
    Base* ceiling = new Ceil(add);
    Iterator* testIt = ceiling->create_iterator();
    testIt->first();
    Base* iterated = testIt->current();
    EXPECT_EQ(iterated->evaluate(), 5.5);
}

TEST(IteratorTest, NullTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Iterator* testIt = tree->create_iterator();
    
    testIt->first();
    EXPECT_EQ(testIt->current(), nullptr);
}

TEST(IteratorTest, BinaryTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Iterator* testIt = tree->create_iterator();
    double two1 = 2;
    double three1 = 3;

    testIt->first();
    std::string left = testIt->current()->stringify();
    testIt->next();
    std::string right = testIt->current()->stringify();
    EXPECT_EQ(left, std::to_string(three1));
    EXPECT_EQ(right, std::to_string(two1));
}


TEST(IteratorTest, PreorderTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3*1";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Iterator* testIt = new PreorderIterator(tree);
    double two1 = 1;
    double three1 = 3;

    testIt->first();
    std::string left = testIt->current()->stringify();
    testIt->next();
    std::string right = testIt->current()->stringify();
    EXPECT_EQ(left, std::to_string(three1));
    EXPECT_EQ(right, std::to_string(two1));
}

#endif

