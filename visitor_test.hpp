#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "factory.hpp"
#include "iterator.hpp"
#include "decorator.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include "visitor.hpp"
#include "base.hpp"
#include "rand.hpp"

TEST(VisitorTest, regTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2*6+4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 7);
}

TEST(VisitorTest, ComplexTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2**6+4/2-8*5";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 13);
}

TEST(VisitorTest,ComplexTest1){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "1+2**6+7/2-8*5";
    argv[2] = "\0";
    Base* ftree = test->parse(argv, 2);
    Base* tree = new Floor(ftree);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 14);
}

TEST(VisitorTest, ComplexTest2){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "9+8**7+6/5-4*3";
    argv[2] = "\0";
    Base* ftree = test->parse(argv, 2);
    Base* wrap = new Abs(ftree);
    Base* tree = new Floor(wrap);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 15);
}

TEST(VisitorTest, TruncTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "1+2**3+4/5-6*7";
    argv[2] = "\0";
    Base* ftree = test->parse(argv, 2);
    Base* trun = new Trunc(ftree);
    Base* wrap = new Abs(trun);
    Base* tree = new Floor(wrap);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 16);
}

TEST(VisitorTest, ParenTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+7**9+4/2-4*5";
    argv[2] = "\0";
    Base* ftree = test->parse(argv, 2);
    Base* paren = new Paren(ftree);
    Base* trun = new Trunc(paren);
    Base* wrap = new Abs(trun);
    Base* tree = new Floor(wrap);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }
    int tot_Expression = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();

    EXPECT_EQ(tot_Expression, 17);
}

TEST(VisitorTest, OpTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2*6+4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->op_count(), 4);
}

TEST(VisitorTest, SubTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2*6+4-8";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->sub_count(), 1);
}

TEST(VisitorTest, AddTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2*6+4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->add_count(), 2);
}

TEST(VisitorTest, MultTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2*6+4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->mult_count(), 1);
}

TEST(VisitorTest, PowTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3+2**6+4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->pow_count(), 1);
}

TEST(VisitorTest, DivTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3/2/6/4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Iterator* testIt = new PreorderIterator(treedec);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->div_count(), 3);
}

TEST(VisitorTest, CeilTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3/2/6/4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Ceil(tree);
    Base* wrap = new Ceil(treedec);
    Iterator* testIt = new PreorderIterator(wrap);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->ceil_count(), 1);
}

TEST(VisitorTest, FloorTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3/2/6/4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Floor(tree);
    Base* wrap = new Ceil(treedec);
    Iterator* testIt = new PreorderIterator(wrap);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->floor_count(), 1);
}

TEST(VisitorTest, AbsTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3/2/6/4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* treedec = new Abs(tree);
    Base* wrap = new Ceil(treedec);
    Iterator* testIt = new PreorderIterator(wrap);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->abs_count(), 1);
}

TEST(VisitorTest, RandTest){
    Factory* test = new Factory();
    char* argv[2];
    argv[0] = "./calculator";
    argv[1] = "3/2/6/4";
    argv[2] = "\0";
    Base* tree = test->parse(argv, 2);
    Base* randnum =  new Rand();
    Base* treedec = new Add(tree, randnum);
    Base* wrap = new Ceil(treedec);
    Iterator* testIt = new PreorderIterator(wrap);
    CountVisitor* expVisitor = new CountVisitor();
    
    testIt->first();
    while(!testIt->is_done()){
        testIt->current()->accept(expVisitor);
        testIt->next();
    }

    EXPECT_EQ(expVisitor->rand_count(), 1);
}

#endif

