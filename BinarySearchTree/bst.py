
"""
========================================================================
Binary Search Trees

BigO
    give levels     = l
    n nodes         = 2^l - 1
    thus apprx      = 2^l

    It takes l steps to traverse the tree to the leaf, thus

    Expressed as BigO
            2^l = nodes
        :   log2(nodes) = l

    Best Case:
        Adding nodes:   O log2(n)
        Removing nodes: O log2(n)
        Look up:        O log2(n)

    This is acheived by using 'Divide-and-conquer'

    Worst Case:
        - Only move in a single direction yields a linked list.
        : BigO = O(n) 

    Because of this 'append' are faster with a linked list.

: zach wolpe
: zach.wolpe@medibio.com.au
: 03 July 2023
========================================================================
"""


class Node:
    def __init__(self, value) -> None:
        self.left   = None
        self.right  = None
        self.value  = value


class BinarySearchTree:
    def __init__(self, value) -> None:
        self.root = Node(value)

    def insert(self, value):
        temp = self.root
        while True:
            if (temp.value == value): return False;
            if (value < temp.value):
                if (temp.left is None):
                    temp.left = Node(value)
                    return True
                temp = temp.left
            else:
                if (temp.right is None):
                    temp.right = Node(value)
                    return True
                temp = temp.right
    
    def contains(self, value):
        temp = self.root
        while temp:
            if (temp.value == value): return True
            if (temp.value < value):
                temp = temp.left
            else: temp = temp.right
        return False
    


if __name__ == '__main__':
    BST = BinarySearchTree(11)
    BST.insert(32)
    BST.insert(-2)
    print(BST.root.right)
    print("Contains: ", BST.contains(2))
    print("Contains: ", BST.contains(32))

    print('....')
    my_tree = BinarySearchTree(21)
    my_tree.insert(47)
    my_tree.insert(21)
    my_tree.insert(76)
    my_tree.insert(18)
    my_tree.insert(27)
    my_tree.insert(52)
    my_tree.insert(82)

    print('BST Contains 27:')
    print(my_tree.contains(27))

    print('\nBST Contains 17:')
    print(my_tree.contains(17))
                    