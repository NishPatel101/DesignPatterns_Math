#ifndef _VECTORCONTAINER_HPP_
#define _VECTORCONTAINER_HPP_

#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
#include <vector>
#include <stdexcept>

class Sort;
class Container;

class VectorContainer : public Container {
	protected:
		Sort* sort_function;
		std::vector<Base*> data; 
	public:
		//VectorContainer() : sort_function(nullptr) { }
		//VectorContainer(Sort* function) : sort_function(function) { }

		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}

		void add_element(Base* element) {
			data.push_back(element);
		}

		void print() {
			if (data.size() > 0) {
				for (int i = 0; i < data.size(); i++)
					data.at(i)->stringify() + ", ";
			}
		}

		void sort() {
			if (!sort_function)
				throw sort_function;
			else
				sort_function->sort(this);	
		}

		void swap(int i, int j) {
			std::swap(data.at(i), data.at(j));	
		}

		Base* at(int i) {
			return data.at(i);
		}

		int size() {
			return data.size();
		}	
};

#endif //_VECTORCONTAINER_HPP_
