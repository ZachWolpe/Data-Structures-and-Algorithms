/**
========================================================================
@file quick_sort.cpp

Big O:

    Space Complexity: O(1)
        - no new items/copies created.

    Time Complexity: O(n^2)
        - average case (great performance): O(n log n)
        - worst case (if data is sorted or almost sorted): O(n^2)


: zach wolpe
: zach.wolpe@medibio.com.au
: 17 July 2023
========================================================================
*/


#include <iostream>

void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex]   = array[secondIndex];
    array[secondIndex]  = temp;
};

int pivot(int array[], int pivotIndex, int endIndex) {
    // loop
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
            swapIndex ++;
            swap(array, swapIndex, i);
        }
    };
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
};

void quickSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);
};

int main() {
    int myArray[] = {4,6,1,7,3,2,5};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    quickSort(myArray, 0, size-1);
    for (auto value : myArray) {
        std::cout << value << " ";
    }
    return 0;
};