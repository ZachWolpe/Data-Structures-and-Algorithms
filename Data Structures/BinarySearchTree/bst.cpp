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

#include <iostream>

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left  = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree (int value) {
            Node* node = new Node(value);
            root = node;
        }

        // add a destructor
        void destroy(Node* node) {
            // recursive destructor.
            if (node->left)  destroy(node->left);
            if (node->right) destroy(node->right);
            delete node;
        };

        ~BinarySearchTree() {destroy(root);}

        bool insert(int value) {
            Node* node = new Node(value);
            Node* temp = root;
            while (true) {
                if (temp->value == node->value) return false;
                if (temp->value < value) {
                    if (temp->left == nullptr) {
                        temp->left = node;
                        return true;
                    }
                    temp = temp->left;
                }
                else {
                    if (temp->right == nullptr) {
                        temp->right = node;
                        return true;
                    }
                    temp->right = node;
                }
            }
        }

        bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;
            while (temp) {
                if (temp->value == value) return true;
                else if (temp->value < value) temp = temp->left;
                else temp = temp->right;
            }
            return false;
        }
};


int main() {
    BinarySearchTree* BST = new BinarySearchTree(11);
    BST->insert(432);
    BST->insert(-2);
    std::cout << BST->root->right << std::endl;
    std::cout << "Contains: " << BST->contains(333) << std::endl;
    std::cout << "Contains: " << BST->contains(-2) << std::endl;
    return 0;
}
