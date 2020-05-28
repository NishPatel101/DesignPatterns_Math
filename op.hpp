#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
	private:
		double num;
	public:
		Op(double value) : Base() {num = value;}
		virtual double evaluate() {return num;}
		virtual std::string stringify() {return std::to_string(num);}
		virtual Iterator* create_iterator(){return new NullIterator(this);}
		virtual Base* get_left(){return nullptr;}
		virtual Base* get_right(){return nullptr;}
		virtual void accept(CountVisitor* visitor){visitor->visit_op();}
};
#endif //__OP_HPP__

