/**
========================================================================
@file tree_traverse.cpp

Traversal of a Binary Search Tree.

Big O:
    Space Complexity:
    Time Complexity:

: zach wolpe
: zach.wolpe@medibio.com.au
: 17 July 2023
========================================================================
*/


#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>


class Node { 
public: 
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left        = nullptr;
        right       = nullptr;
    }
};


class BinarySearchTree {
public:
    Node* root;

public:
    BinarySearchTree() {root = nullptr;}
    ~BinarySearchTree() {destructor(root);}
    void destructor(Node* node) {
        if (node) {
            destructor(node->left);
            destructor(node->right);
            delete node;
        }
    }
    void insert (int value) {
        Node* node = new Node(value);
        if (root == nullptr) {
            root = node;
            return;
        }
        Node* temp = root;
        while (true) {
            if (node->value == temp->value) return;
            if (node->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = node;
                    return;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) {
                    temp->right = node;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value) {
        if (root == nullptr) return false;
        Node* temp = root;
        while(temp) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void BFS() {
        std::queue<Node*> myQueue;
        myQueue.push(root);

        while (myQueue.size() > 0) {
            Node* curr = myQueue.front();
            myQueue.pop();
            std::cout << curr->value << " -> ";
            if (curr->left) {
                myQueue.push(curr->left);
            }
            if (curr->right) {
                myQueue.push(curr->right);
            }
        }
    }

    void DFS(Node* node, std::string order="preorder") {
        if (order != "preorder" && order != "postorder" && order != "inorder") {
            // raise value error.
            throw std::invalid_argument("\n\nInvalid order argument\n\n");
        };
        if (order == "preorder")
            std::cout << node->value << " -> ";
        if (node->left)  DFS(node->left);
        if (order == "inorder")
            std::cout << node->value << " -> ";
        if (node->right) DFS(node->right);
        if (order == "postorder")
            std::cout << node->value << " -> ";
    }

    // overload
    void DFS(std::string order) {DFS(root , order);}
};



int main() {

    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    std::cout << "Breadth First Search:\n";
    myBST->BFS();
    std::cout << " \n ";
    myBST->DFS("preorder");     std::cout << " \n ";
    myBST->DFS("postorder");    std::cout << " \n ";
    myBST->DFS("inorder");      std::cout << " \n ";

    return 0;
};