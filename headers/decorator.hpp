#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"

class Decorator : public Base {
   
    protected:
	Base* child;

    public:
        /* Constructors */
            Decorator(Base* c) {
	    this->child = c;
	};

        /* Virtual Functions */
        virtual double evaluate() {
	    return this->child->evaluate();
	}

        virtual std::string stringify() {
	    return this->child->stringify();
	};

	void set_child(Base* c) {
	    this->child = c;
	}
};

#endif //__DECORATOR_HPP__

