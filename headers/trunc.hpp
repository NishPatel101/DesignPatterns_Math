#ifndef _TRUNC_HPP_
#define _TRUNC_HPP_

#include "decorator.hpp"
#include "op.hpp"

class Trunc : public Decorator {
	private:
		Base* value;
	public:
		Trunc(Base* value) : Decorator(value) {
			this->value = value;
		}

		virtual double evaluate() {
			return value->evaluate();
		}

		virtual std::string stringify() {
			return std::to_string(value->evaluate());
		}
};
#endif
		
