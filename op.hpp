#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base {
    private:
	double value;	

    public:
        Op(double value) : Base() {
	    this->value = value;
	}
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string((int) value); }
	
	virtual Iterator* create_iterator() {
		Iterator* it = new NullIterator(this);
		return it;
	}
	void accept(CountVisitor* c) {
                c->visit_op();
        }
};

#endif //__OP_HPP__
