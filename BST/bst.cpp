/**
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
*/

class Node {
    public:
        
}
