#ifndef _PAREN_HPP_
#define _PAREN_HPP_

#include "decorator.hpp"
#include "op.hpp"


class Paren : public Decorator {
        private:
                Base* value;

        public:
                Paren(Base* value) : Decorator(value) {
                        this->value = value;
                }

                virtual double evaluate() {
			return value->evaluate();
		}
		
                virtual std::string stringify() {
			return "(" + value->stringify() + ")";
		}
};
                
#endif
