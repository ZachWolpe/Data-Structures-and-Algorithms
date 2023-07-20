/**
========================================================================
@file merge_sort.cpp

Big O:

Space Complexity: O(n)
    - New arrays are required, however they take the same space in memory.

Time Complexity: 
    = O(n log(n) + n)
    = O(n log(n))       // drop non dominants.


: zach wolpe
: zach.wolpe@medibio.com.au
: 14 July 2023
========================================================================
*/


#include <iostream>

void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    
    // split array into two
    int leftArraySize  = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];
    for (int i=0; i<leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int i=0; i<rightArraySize; i++)
        rightArray[i] = array[midIndex + i + 1];

    // sort by selecting the minimum at each index
    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize)
        if (leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        } else {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    
    // complete cycle
    while (i < leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    };
    while (j < rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    };

};

void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex,  midIndex);
    mergeSort(array, midIndex+1, rightIndex);
    merge(array, leftIndex, midIndex, rightIndex);

};

int main() {
    int myArray[] = {1,3,7,8,45,3,4,2,4,5,6};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    mergeSort(myArray, leftIndex, rightIndex);
    for (auto value : myArray) {
        std::cout << value << " ";
    }
    return 0;

};