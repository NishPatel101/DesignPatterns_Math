#ifndef __SUB_HPP__
#define __SUB_HPP__

class Sub: public Base{
	private:
		Base* value1;
		Base* value2;
	public:
		Sub(Base* a, Base* b) {value1 = a; value2 = b;}
		virtual double evaluate() {return value1->evaluate() - value2->evaluate();}
		virtual std::string stringify() {return value1->stringify() + " - " +  value2->stringify();}
		virtual Iterator* create_iterator()
		{
				return new BinaryIterator(this);
		}
		virtual Base* get_left(){return value1;};
 	    virtual Base* get_right(){return value2;};
		virtual void accept(CountVisitor* visitor){visitor->visit_sub();}
};
#endif //__SUB_HPP__

