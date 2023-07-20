"""
========================================================================
@file selection_sort.py

: zach wolpe
: zach.wolpe@medibio.com.au
: 18 July 2023
========================================================================
"""


def selection_sort(arr):
    for i in range(len(arr)-1):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
        if i != min_idx:
            temp = arr[i]
            arr[i] = arr[min_idx]
            arr[min_idx] = temp
    return arr
            

if __name__ == '__main__':
    
    array = [1, 222, 233, 4, 5, 6, 97, 8, 9]
    array = selection_sort(array)
    [print(i, end=' -> ') for i in array]
    print()