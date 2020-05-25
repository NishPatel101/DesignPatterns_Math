#ifndef _ADD_HPP_
#define _ADD_HPP_

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <string>

class Add : public Base {
        private:
                Base* value1;
                Base* value2;

        public:
                Add(Base* value1, Base* value2) : Base() {
                        this->value1 = value1;
                        this->value2 = value2;
                }

		virtual double evaluate() { return (value1->evaluate() + value2->evaluate()) ; }
                virtual std::string stringify() { return " " + std::to_string((int) value1->evaluate()) + " + " +  std::to_string((int) value2->evaluate()) + " ";
		}
		virtual Iterator* create_iterator() {
			Iterator* it = new BinaryIterator(this);
			return it;
		}
		void accept(CountVisitor* c) {
			c->visit_add();
		}
};

#endif // _ADD_HPP_
