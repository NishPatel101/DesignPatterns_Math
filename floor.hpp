#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "decorator.hpp"
#include <cmath>

class Floor: public Decorator{
	private:
		Base* exp;
	public:
		Floor(Base* e){exp = e;}

		virtual double evaluate(){
			return floor(exp->evaluate());
		}

		virtual std::string stringify(){
			return "Floor(" + exp->stringify() + ")";
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
		virtual void accept(CountVisitor* visitor){visitor->visit_floor();}
};

#endif

