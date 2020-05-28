#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>

class Pow: public Base {
	private:
		Base* base;
		Base* power;
	public:
		Pow(Base* x, Base* y) {
			base = x; 
			power = y;
		}
		virtual double evaluate() {
			return pow(base->evaluate(), power->evaluate());
		}
		virtual std::string stringify() {
			return base->stringify() + " ** " + power->stringify();
		}
		virtual Iterator* create_iterator()
		{
			return new BinaryIterator(this);
		}
		virtual Base* get_left(){return base;}
		virtual Base* get_right(){return power;}
		virtual void accept(CountVisitor* visitor){visitor->visit_pow();}
};

#endif //__POW_HPP__

