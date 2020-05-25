#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"

class Div : public Base {
        private:
                Base* value1;
                Base* value2;

        public:
                Div(Base* value1, Base* value2) : Base() {
                        this->value1 = value1;
                        this->value2 = value2;
                }

                virtual double evaluate() { return (value1->evaluate() / value2->evaluate()) ; }
                virtual std::string stringify() { return " " + std::to_string(value1->evaluate()) + " / " +  std::to_string(value2->evaluate()) + " "; }
                virtual Iterator* create_iterator() {
                        Iterator* it = new BinaryIterator(this);
                }

};

#endif // _DIV_HPP_

