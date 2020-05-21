#ifndef _SELECTION_SORT_HPP_
#define _SELECTION_SORT_HPP

#include "container.hpp"
//#include "base.hpp"
#include "sort.hpp"
//#include "VectorContainer.hpp"
#include <vector>

class Container;
class Sort;

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort() : Sort() {}

        /* Pure Virtual Functions */
        void sort(Container* num) {
		int i, j, first, temp;
      		int numLength = num->size();
      		for (i = numLength - 1; i > 0; i--)
     		{
           		first = 0;                 // initialize to subscript of first element
           		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
          		{
                 		if (num->at(j) < num->at(first))
                 		first = j;
          		}
         		num->swap(first, i);   // Swap smallest found with element in position i.
     		}				
     		return;
	}
};
#endif
