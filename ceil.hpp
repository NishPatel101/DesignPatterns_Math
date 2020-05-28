#ifndef _CEIL_HPP_
#define _CEIL_HPP_

#include "decorator.hpp"
#include <cmath>

class Ceil : public Decorator{
	private:
		Base *exp;
	public:
		Ceil(Base *e){exp = e;}

		virtual double evaluate(){ 
			return ceil(exp->evaluate());
		}

		virtual std::string stringify(){
			return "Ceil(" + exp->stringify() + ")";
		}

		virtual Iterator* create_iterator(){
			return new UnaryIterator(this);
		}

		virtual Base* get_left(){
			return exp;
		}

		virtual Base* get_right(){
			return nullptr;
		}
		virtual void accept(CountVisitor* visitor){visitor->visit_ceil();}
};

#endif

