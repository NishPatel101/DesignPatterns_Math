#ifndef _ABS_HPP_
#define _ABS_HPP_


#include <math.h>
#include <stdlib.h>
#include "decorator.hpp"
#include "op.hpp"


class Abs : public Decorator {
        private:
                Base* value;

        public:
                Abs(Base* value) : Decorator(value) {
                        this->value = value;
                }

                virtual double evaluate() { return abs(Decorator::evaluate()) ; }
                virtual std::string stringify() { return NULL; }
                };
               
#endif // _ABS_HPP_
