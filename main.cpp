#include <iostream>

#include "base.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "factory.hpp"
#include "decorator.hpp"
#include "ceil.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include "floor.hpp"
#include "iterator.hpp"
#include "preorder_iterator.cpp"
#include "unary_iterator.cpp"
#include "binary_iterator.cpp"
#include "visitor.hpp"

void print(CountVisitor* visitor);

int main(int argc, char** argv) {
    Factory* expFact = new Factory();
    CountVisitor* expVisitor = new CountVisitor();
    Base* randTree = expFact->parse(argv, argc);
    Base* randnum = new Rand();
    Base* expTree = new Add(randTree, randnum);
    std::cout << expTree->stringify() << std::endl;
    Base* dummy = new Ceil(expTree);
    Iterator* expIt = new PreorderIterator(dummy);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }
 
    print(expVisitor);
    std::cout << std::endl;

    Base* ceiltree = new Ceil(expTree);
    std::cout << ceiltree->stringify() << std::endl;
    expVisitor =  new CountVisitor();
    Base* dummy2 = new Ceil(ceiltree);
    expIt = new PreorderIterator(dummy2);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }

    print(expVisitor);
    std::cout << std::endl;

    Base* parentree = new Paren(ceiltree);
    std::cout << parentree->stringify() << std::endl;
    expVisitor =  new CountVisitor();
    Base* dummy3 = new Ceil(parentree);
    expIt = new PreorderIterator(dummy3);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }

    print(expVisitor);
    std::cout << std::endl;

    Base* abstree = new Abs(parentree);
    std::cout << abstree->stringify() << std::endl;
    expVisitor =  new CountVisitor();
    Base* dummy4 = new Ceil(abstree);
    expIt = new PreorderIterator(dummy4);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }

    print(expVisitor);
    std::cout << std::endl;

    Base* trunctree = new Trunc(abstree);
    std::cout << trunctree->stringify() << std::endl;
    expVisitor =  new CountVisitor();
    Base* dummy5 = new Ceil(trunctree);
    expIt = new PreorderIterator(dummy5);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }

    print(expVisitor);
    std::cout << std::endl;

    Base* floortree = new Floor(trunctree);
    std::cout << floortree->stringify() << std::endl;
    expVisitor =  new CountVisitor();
    Base* dummy6 = new Ceil(floortree);
    expIt = new PreorderIterator(dummy6);
    expIt->first();
    while(!expIt->is_done()){
        expIt->current()->accept(expVisitor);
        expIt->next();
    }

    print(expVisitor);

    return 0;
}

void print(CountVisitor* expVisitor){
    int totalExp = expVisitor->abs_count() + expVisitor->add_count() + expVisitor->ceil_count() + expVisitor->div_count() + expVisitor->floor_count() + expVisitor->mult_count() + expVisitor->op_count() + expVisitor->paren_count() + expVisitor->pow_count() + expVisitor->rand_count() + expVisitor->sub_count() + expVisitor->trunc_count();
    std::cout << "abs count " << expVisitor->abs_count() << std::endl;
    std::cout << "add count " << expVisitor->add_count() << std::endl;
    std::cout << "ceil count " << expVisitor->ceil_count() << std::endl;
    std::cout << "div count " << expVisitor->div_count() << std::endl;
    std::cout << "floor count " << expVisitor->floor_count() << std::endl;
    std::cout << "mult count " << expVisitor->mult_count() << std::endl; 
    std::cout << "op count " << expVisitor->op_count() << std::endl;
    std::cout << "paren count " << expVisitor->paren_count() << std::endl;
    std::cout << "pow count " << expVisitor->pow_count() << std::endl;
    std::cout << "rand count " << expVisitor->rand_count() << std::endl;
    std::cout << "sub count " << expVisitor->sub_count() << std::endl; 
    std::cout << "trunc count " << expVisitor->trunc_count() << std::endl;
    std::cout << "total expressions in tree:  " << totalExp << std::endl;
}

