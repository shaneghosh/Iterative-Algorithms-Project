#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>
#include <vector>


template <typename T>
void swap_vectors2(T& vec1, T& vec2)
{
    T holder;
    holder = vec1;
    vec1 = vec2;
    vec2 = holder;
}


template <typename T>

// Function enabling selection sort of a vector
std::vector<T> selectionSort(std::vector<T>& someVec)
{
    int swapcounter{0};
    int compcounter{0};

    // the minimum value storage
    int smallestValue;

    //iterates over the list and then sets the value to the minimum values
    //checks for smaller values in the front
    //if there is a smaller value in the front it is the minimum value
    for (int i{0}; i < someVec.size()-1; i++)
    {
        smallestValue = i;

        for (int j=i+1; j < someVec.size(); j++)
        {
            compcounter++;

            if (someVec[j] < someVec[smallestValue])
                smallestValue = j;
        }

        // if the minimum value isn't the current value
        // minimum value and current value are switched
        // min value in the list is now at the front
        if (smallestValue != i)
        {
             swapcounter++;

             swap_vectors2(someVec[i], someVec[smallestValue]);
        }
    }
    cout << "Number of comparisons: " << compcounter << endl;
    cout << "Number of swaps: " << swapcounter << endl;
    return someVec;
}

#endif // SELECTIONSORT_H
