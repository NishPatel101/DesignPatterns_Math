#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"
#include <cmath>

class Abs:public Decorator{
	private:
		Base* exp;
	public:
		Abs(Base *e){exp = e;}

		virtual double evaluate(){
			return std::abs(exp->evaluate());
		}

		virtual std::string stringify(){
			return "Abs(" + exp->stringify() + ")";
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
		virtual void accept(CountVisitor* visitor){visitor->visit_abs();}
};

#endif

