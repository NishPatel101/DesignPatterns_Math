#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "decorator.hpp"

class Paren: public Decorator{
	private:
		Base* exp;
	public:
		Paren(Base *e){exp = e;}

		virtual double evaluate(){
			return exp->evaluate();
		}

		virtual std::string stringify(){
			return "(" + exp->stringify() + ")";
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
		virtual void accept(CountVisitor* visitor){visitor->visit_paren();}
};

#endif

