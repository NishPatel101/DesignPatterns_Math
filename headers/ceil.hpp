#ifndef _CEIL_HPP_
#define _CEIL_HPP_


#include <math.h>
#include "decorator.hpp"
#include "op.hpp"


class Ceil : public Decorator {
        private:
                Base* value;

        public:
                Ceil(Base* value) : Decorator(value) {
                        this->value = value;
                }

                virtual double evaluate() { return ceil(Decorator::evaluate()) ; }
                virtual std::string stringify() { return NULL ; }

                };
                
#endif // _CEIL_HPP_
