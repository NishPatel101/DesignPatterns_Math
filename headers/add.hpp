#ifndef _ADD_HPP_
#define _ADD_HPP_

#include "base.hpp"
#include "op.hpp"

class Add : public Base {
	private:
		Base* value1;
		Base* value2;

	public:
		Add(Base*value1, Base*value2) : Base() {
			this->value1 = value1;
			this->value2 = value2;
		 }

	virtual double evaluate() { return (value1->evaluate() + value2->evaluate()) ; }

	virtual std::string stringify() { return (value1->stringify()) + " + " + (value2->stringify());} 
	//virtual std::string stringify() { return std::to_string(value1->stringify()) + "+" + std::to_string(value2->stringify());} 
};

#endif //_ADD_HPP_

