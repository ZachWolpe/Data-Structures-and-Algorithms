/**
========================================================================
@file bubblesort.cpp

: zach wolpe
: zach.wolpe@medibio.com.au
: 14 July 2023
========================================================================
*/

#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    // passing array only passes the address of the first item in the array, not the size. 
    // we do not return a new array, but update an existing one.
    for (int i=size-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (array[j] > array[j+1]) {
                int temp    = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            } 
        }
    }
}

int main() {
    int myArray[] = {6,4,2,5,3,4,2};
    int size = sizeof(myArray) / sizeof(myArray[0]); // number of bytes in array
    bubbleSort(myArray, size);

    for (auto value : myArray) {
        cout << value << " ";
    }
    return 0;
};