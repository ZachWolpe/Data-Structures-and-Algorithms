
"""
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
: 18 July 2023
========================================================================
"""

class quickSort:

    @staticmethod
    def swap(array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    @staticmethod
    def pivot(array, pIndex, endIndex):
        swapIndex = pIndex
        for i in range(pIndex+1, endIndex+1):
            if array[i] < array[pIndex]:
                swapIndex += 1
                quickSort.swap(array, swapIndex, i)
        quickSort.swap(array, pIndex, swapIndex)
        return swapIndex
    
    @staticmethod
    def quick_sorter(array, left, right):
        if left < right:
            pivotIndex = quickSort.pivot(array, left, right)
            quickSort.quick_sorter(array, left, pivotIndex-1)
            quickSort.quick_sorter(array, pivotIndex+1, right)
        return array

    @staticmethod
    def quick_sort(array):
        return quickSort.quick_sorter(array, 0, len(array)-1)

if __name__ == '__main__':
    
    array = [1, 222, 233, 4, 5, 6, 97, 8, 9]
    array = quickSort.quick_sort(array)
    [print(i, end=' -> ') for i in array]
    print()