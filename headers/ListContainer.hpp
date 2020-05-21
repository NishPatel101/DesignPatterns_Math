#ifndef _LIST_CONTAINER_HPP_
#define _LIST_CONTAINER_HPP_

#include "container.hpp"
#include "base.hpp"
#include "sort.hpp"
#include <list>
#include <iterator>

class Sort;
class Container;

class ListContainer : public Container {
     //   private:
         
	protected:
	    std::list<Base*> expressions;
		Sort* sort_function;
        public:

	    void add_element(Base* element) {
	    	expressions.push_back(element);
	    }

	void set_sort_function(Sort* sort_function){
		sort_function = sort_function;
	}

	    void print(){
		for(auto i = expressions.begin(); i != expressions.end(); ++i ) {
		    std::cout << ' ' << *i;
		}
	    }
	    
	    void sort() {
	    	// this->sort_function->sort(this);
	     sort_function->sort(this);
	    }
	    void swap(int i, int j){
		
		std::list<Base*>::iterator it_i = this->expressions.begin();
		std::advance(it_i,i);
		
		std::list<Base*>::iterator it_j = this->expressions.begin();
		advance(it_j,j);

		Base* temp = (*it_i);
		(*it_i) = (*it_j);
		(*it_j) = temp;

	    }
	    Base* at(int i) {
		std::list<Base*>::iterator it = expressions.begin();
	  	std::advance(it,i);
		return *it;
	    }
	    int size() {
		return expressions.size();
	    }
};

#endif // _LIST_CONTAINER_HPP_
