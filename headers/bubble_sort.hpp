#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"
#include <iostream>
 
class Container;
class Sort;

class BubbleSort : public Sort {
    public:
	BubbleSort() : Sort() {}
        /* Pure Virtual Functions */
        void sort(Container* container) {

         int i, j, flag = 1;
         int numLength = container->size(); 
         for(i = 1; (i <= numLength) && flag; i++) {

            flag = 0;

              for (j=0; j < (numLength -1); j++) {
                   if (container->at(j+1) > container->at(j)) {
                        container->swap(j,j+1);
                        flag = 1;
                   }
              }
          }
        }
};

#endif //__BUBBLE_SORT_HPP__

