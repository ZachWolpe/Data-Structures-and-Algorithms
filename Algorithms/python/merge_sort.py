"""
========================================================================
@file merge_sory.py

Big O:

Space Complexity: O(n)
    - New arrays are required, however they take the same space in memory.

Time Complexity: 
    = O(n log(n) + n)
    = O(n log(n))       // drop non dominants.


: zach wolpe
: zach.wolpe@medibio.com.au
: 18 July 2023
========================================================================
"""

def merge(arr1, arr2):
    combined = []
    i = 0
    j = 0
    while i < len(arr1) and j < len(arr2):
        if arr2[j] > arr1[i]:
            combined.append(arr1[i])
            i += 1
        else:
            combined.append(arr2[j])
            j += 1
    
    while i < len(arr1):
        combined.append(arr1[i])
        i += 1
    
    while j < len(arr2):
        combined.append(arr2[j])
        j += 1

    return combined


def merge_sort(my_list):
    if len(my_list) == 1:
        return my_list
    mid = int(len(my_list)/2)
    left = my_list[:mid]
    right = my_list[mid:]
    return merge(merge_sort(left), merge_sort(right))




if __name__ == '__main__':
    
    array = [1, 222, 233, 4, 5, 6, 97, 8, 9]
    array = merge_sort(array)
    [print(i, end=' -> ') for i in array]
    print()