#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <random>
#include "op.hpp"

class Rand: public Base {
	private:
		Base* value;
	public:
		Rand() {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist100(0,100);
			value = new Op(dist100(rng));	
		}
		virtual double evaluate() {return value->evaluate();}
		virtual std::string stringify() {return value->stringify();}
		virtual Iterator* create_iterator(){return new NullIterator(this);}

		virtual Base* get_left(){
			return nullptr;
		}

		virtual Base* get_right(){
			return nullptr;
		}
		virtual void accept(CountVisitor* visitor){visitor->visit_rand();}
};

#endif //__RAND_HPP__

