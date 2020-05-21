#ifndef _SUB_HPP_
#define _SUB_HPP_

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
	private:
		Base* value1;
		Base* value2;

	public:
		Sub(Base*value1, Base*value2) : Base() {
			this->value1 = value1;
			this->value2 = value2;
		 }

	virtual double evaluate() { return (value1->evaluate() - value2->evaluate()) ; }
	virtual std::string stringify() { return (value1->stringify()) + " - " + (value2->stringify());} 
//	virtual std::string stringify() { return std::to_string(value1->evaluate()) + "-" + std::to_string(value2->evaluate());} 	
};

#endif //_SUB_HPP_

