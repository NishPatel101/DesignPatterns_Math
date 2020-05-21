#ifndef _FLOOR_HPP_
#define _FLOOR_HPP_


#include <math.h>
#include "decorator.hpp"
#include "op.hpp"


class Floor : public Decorator {
        private:
                Base* value;

        public:
                Floor(Base* value) : Decorator(value) {
                        this->value = value;
                }

                virtual double evaluate() { return floor(Decorator::evaluate()) ; }
                virtual std::string stringify() { return NULL; }
};

#endif // _FLOOR_HPP_

