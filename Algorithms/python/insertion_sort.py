"""
========================================================================
@file insertion_sort.py

Big O:
    worst case: O(n^2)
    best case:  O(n)

: zach wolpe
: zach.wolpe@medibio.com.au
: 18 July 2023
========================================================================
"""

def insertion_sort(array):
    for i in range(1, len(array)):
        temp = array[i]
        j = i-1
        while j > -1 and temp < array[j]:
            array[j+1] = array[j]
            array[j] = temp
            j -= 1
    return array


if __name__ == '__main__':
    
    array = [1, 222, 233, 4, 5, 6, 97, 8, 9]
    array = insertion_sort(array)
    [print(i, end=' -> ') for i in array]
    print()