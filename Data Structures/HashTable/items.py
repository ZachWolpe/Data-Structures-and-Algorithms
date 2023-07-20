"""
========================================================================
@file items.cpp

An illustrutation of how to use a hashmap to reduce time complexity from O(n^2) to O(n).

: zach wolpe
: zach.wolpe@medibio.com.au
: 17 July 2023
========================================================================
"""

class items:
    @staticmethod
    def find_common_items(list1, list2):
        for i in list1:
            for j in list2:
                if i == j:
                    print(i)

    @staticmethod
    def find_common_fast(list1, list2):
        map = {}
        for i in list1:
            if i not in map:
                map[i] = True
        
        for j in list2:
            if j in map:
                print(j)




if __name__ == '__main__':
    l1, l2 = [1, 23, 3, 4], [ 4, 6, 7, 8, 9]
    items.find_common_items(l1, l2)
    items.find_common_fast(l1, l2)