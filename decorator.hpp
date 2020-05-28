#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"

class Decorator: public Base{
	public:
		Decorator(){};
		virtual double evaluate() = 0;
		virtual std::string stringify() = 0;
		virtual Iterator* create_iterator() = 0;
		virtual Base* get_left() = 0;
		virtual Base* get_right() = 0;
		virtual void accept(CountVisitor* ) = 0;
};

#endif

