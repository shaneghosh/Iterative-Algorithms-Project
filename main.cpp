#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "mergesort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"

using namespace std;

//function to input and output files and use input file data and produce output files with data
void inputFile(string fileName, int alg)
{
    //Files input
    ifstream inputFile("/Users/shaneghosh/Desktop/Schas Stuff/Grade 11 Files/Programming 25 (Grade 11)/Grade 11 C++/CSE 3110 Iterative Algorithm - I/Assignments/" + fileName + ".txt", ios::in);
    if(!inputFile)
    {
        cerr << "Unable to Open Input File \"NinetyHundred.txt\"\nExiting. . .\n";
        //return 1;
    }

    //Files output
    ofstream outputFile(fileName + "_output.txt", ios::out | ios::trunc);
    if(!outputFile)
    {
        cerr << "Unable to Open or Create Output File \"90_percent_sorted_100_values_output.txt\"\nExiting. . .\n";
        //return 1;
    }

    //Input file txt vector creation
    vector<int> numbers;
    int currentNum;
    while(true)
    {
        inputFile >> currentNum;
        if(inputFile.good())
            numbers.push_back(currentNum);
        else
            break;
    }


    // bubble sort numbers ascending


    //Clock starts here
    auto start = chrono::steady_clock::now();
    switch(alg)
    {
    case 1:
        bubbleSort(numbers);
        break;

    case 2:
        insertionSort(numbers);
        break;

    case 3:
        selectionSort(numbers);
        break;

    case 4:
        mergeSort(numbers);
        break;
    }

    //Clock ends here
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    // output sorted numbers into sortedNumbers.txt
    for(int number : numbers)
        outputFile << number << '\n';
    cout << "Elapsed Time: " << elapsed_seconds.count() << "s" << endl;
}


//Main "driver code"
int main()
{
    int algNum;
    string userFile;

    //
    cout << "Please make your choice of Algorithm: " << endl;
    cout << "1) Bubble Sort" << endl;
    cout << "2) Insertion Sort" << endl;
    cout << "3) Selection Sort " << endl;
    cout << "4) Merge Sort " << endl;

    // User enters choice of algorithm
    cout << "Please enter your choice of algorithm: ";
    cin >> algNum;

    //Uses enters files name
    cout << "Please enter your choice of file name: ";
    cin >> userFile;

    //Runs input file function
    inputFile(userFile, algNum);

    return 0;
}
