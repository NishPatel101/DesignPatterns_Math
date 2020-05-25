#ifndef _MULT_HPP_
#define _MULT_HPP_

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Mult : public Base {
        private:
                Base* value1;
                Base* value2;

        public:
                Mult(Base* value1, Base* value2) : Base() {
                        this->value1 = value1;
                        this->value2 = value2;
                }

                virtual double evaluate() { return (value1->evaluate() * value2->evaluate()) ; }
                virtual std::string stringify() { return " " + std::to_string(value1->evaluate()) + " * " +  std::to_string(value2->evaluate()) + " "; }
                virtual Iterator* create_iterator() {
                        Iterator* it = new BinaryIterator(this);
                }
		void accept(CountVisitor* c) {
                        c->visit_mult();
                }

};

#endif // _MULT_HPP_
