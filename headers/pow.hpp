#ifndef _POW_HPP_
#define _POW_HPP_

#include "base.hpp"
#include "op.hpp"
#include <cmath>

class Pow : public Base {
	private:
		Base* value1;
		Base* value2;

	public:
		Pow(Base*value1, Base*value2) : Base() {
			this->value1 = value1;
			this->value2 = value2;
		 }

	virtual double evaluate() { return pow(value1->evaluate(), value2->evaluate()); }

	virtual std::string stringify() { return (value1->stringify()) + " ** " + (value2->stringify());} 
};

#endif //_POW_HPP_

