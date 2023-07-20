/**
========================================================================
@file insertion_sort.cpp

Big O:
    worst case: O(n^2)
    best case:  O(n)

: zach wolpe
: zach.wolpe@medibio.com.au
: 14 July 2023
========================================================================
*/



#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
    for (int i=1; i<size; i++) {
        int temp = array[i];
        int j = i-1;
        // order of operations!
        while (j > -1 && temp < array[j]) {
            array[j+1] = array[j];
            array[j] = temp;
            j--;   
        }
    };
}


int main() {
    int myArray[] = {6,4,2,5,3,4,2};
    int size = sizeof(myArray) / sizeof(myArray[0]); // number of bytes in array
    insertionSort(myArray, size);
    for (auto value : myArray) {
        cout << value << " ";
    }
    return 0;
};