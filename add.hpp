#ifndef __ADD_HPP__
#define __ADD_HPP__

class Add :public Base{
	private:
		Base* value1;
		Base* value2;
	public:
		Add(Base* a, Base*  b){value1 = a; value2 = b;}
		virtual double evaluate(){return value1->evaluate() + value2->evaluate();}
		virtual std::string stringify() {return value1->stringify() + " + " + value2->stringify();}
		virtual Iterator* create_iterator()
		{
			return new BinaryIterator(this);
		}
		virtual Base* get_left(){return value1;};
		virtual Base* get_right(){return value2;};	
		virtual void accept(CountVisitor* visitor){visitor->visit_add();}
};

#endif //__ADD_HPP__

