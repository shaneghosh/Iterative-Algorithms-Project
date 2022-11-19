#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
#include <vector>

template <typename T>
// Function enabling bubblesort of a vector
std::vector<T> insertionSort(std::vector<T>& someVec)
{
    int compcounter{0};
    int swapcounter{0};


    // initiates variable for storage
    int storeVal;

    // Loop over all indexes present in vector someVec
   for(int i{1}; i < someVec.size() ; i++)
   {
       // Sets currVal current iteration index value
       // Sets storeVal to the current value index
      T currVal = someVec[i];
      storeVal = i;
      compcounter++;

      // loops over all indexes in someVec between 0 and storeVa
      // While loop runs if the value before is greater than current
      while(storeVal > 0 && someVec[storeVal-1] > currVal)
      {
          compcounter++;
          // Switches current value with value before it
          // StoreVal (index) decreases by 1
         someVec[storeVal] = someVec[storeVal-1];
         swapcounter++;
         storeVal--;
      }
      someVec[storeVal] = currVal;   //insert in right place
   }
   cout << "Number of comparisons: " << compcounter << endl;
   cout << "Number of swaps: " << swapcounter << endl;
   return someVec;
}


#endif // INSERTIONSORT_H
