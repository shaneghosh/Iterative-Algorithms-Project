#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <vector>


template <typename T>
void swap_vectors(T& vec1, T& vec2)
{
    T holder;
    holder = vec1;
    vec1 = vec2;
    vec2 = holder;
}

template <typename T>

// Function enabling bubblesort of a vector
std::vector<T> bubbleSort(std::vector<T>& someVec)
{
    int swapcounter{0};
    int compcounter{0};
    // Loops for every number present in the vector
    for (int j {0}; j <= someVec.size(); j++)
    {
        // Loops for every index in the vector
        for (int i{0}; i < someVec.size() -1; i++)
        {
            compcounter++;
            // If the current number is greater than the one after it, swap them
            if(someVec[i] > someVec[i+1])
            {
                swapcounter++;
                swap_vectors(someVec[i], someVec[i+1]);

            }
        }
    }
    cout << "Number of comparisons: " << compcounter << endl;
    cout << "Number of swaps: " << swapcounter << endl;
    return someVec;
}

#endif // BUBBLESORT_H
