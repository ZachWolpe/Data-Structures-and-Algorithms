"""
========================================================================
@file bubblesort.py

: zach wolpe
: zach.wolpe@medibio.com.au
: 17 July 2023
========================================================================
"""


def bubble_sort(array):
    """
    :param array: list of numbers to be sorted
    :return: sorted list
    """
    
    for i in range(len(array)-1, 0, -1):
        for j in range(i):
            if array[j] > array[j+1]:
                temp        = array[j]
                array[j]    = array[j+1]
                array[j+1]  = temp
    return array

if __name__ == '__main__':
    
    array = [1, 222, 233, 4, 5, 6, 97, 8, 9]
    array = bubble_sort(array)
    [print(i, end=' -> ') for i in array]
    print()