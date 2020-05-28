#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "decorator.hpp"

class Trunc:public Decorator{
	private:
		Base* exp;
	public:
		Trunc(Base* e){exp = e;}

		virtual double evaluate(){
			return exp->evaluate();
		}

		virtual std::string stringify(){
			return std::to_string(exp->evaluate());
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
		virtual void accept(CountVisitor* visitor){visitor->visit_trunc();}
};

#endif

