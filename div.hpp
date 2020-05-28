#ifndef __DIV_HPP__
#define __DIV_HPP__

class Div: public Base{
	private:
		Base* value1;
		Base* value2;
	public:
		Div(Base* x, Base* y){value1 = x;value2 = y;}
		virtual double evaluate() {
			if(value2 != 0){
				return value1->evaluate() / value2->evaluate();
			}
			else{
				return -0;
			}
		}
		virtual std::string stringify() {
			return  value1->stringify() + " / " + value2->stringify();
		}
		
		virtual Iterator* create_iterator()
		{			
			return new BinaryIterator(this);
		}

		virtual Base* get_left(){return value1;};
		virtual Base* get_right(){return value2;};
		virtual void accept(CountVisitor* visitor){visitor->visit_div();}
};

#endif //__DIV_HPP__

