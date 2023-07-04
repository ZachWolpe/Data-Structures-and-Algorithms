

/*
========================================================================
Linked List

A regular list is stored contiguously in memory.
A linked list (instead) carries metadata that links the nodes - not requiring contiguous memory linking.

BigO
    - append    (add item end):         O(1)
    - Prepend   (add item front):       O(1)
    - Pop       (remove item end):      O(n)
    - Pop First (remove item front):    O(1)
    - Insert    (add item middle):      O(n)
    - Remove    (remove item middle):   O(n)
    - lookup by value:                  O(n)
    - lookup by index:                  O(n)
      
: zach wolpe
: zach.wolpe@medibio.com.au
========================================================================
*/


// header file 
#include <iostream>
using namespace std;


class Node {
    public:
        int value;
        Node *next;
        Node (int value) {
            this -> value = value;
            this -> next  = nullptr;
        }
};


class LinkedList {
    private:
        Node *head;
        Node *tail;
        int length;
    
    public:
        LinkedList(int value) {
            Node *node = new Node(value);
            this->head = node;
            this->tail = node;
            this->length = 1;
        }
        ~LinkedList() {
            // The default destructor will not remove the nodes from memory, only the `this` properties.
            // head, tail and length are all deleted by the default Destructor.
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            
        }
        void printList() {
            Node *temp = head;
            std::cout << "\nLinked List:\n";
            while (temp != nullptr) {
                std::cout << temp->value << std::endl;
                temp = temp->next;
            }
        };
        void getHead() {
            if (head == nullptr) {
                std::cout << "Head: nullptr" << std::endl;
            } else {
                std::cout << "Head: " << head->value << std::endl;
            }
        };
        void getTail() {
            if (tail == nullptr) {
                std::cout << "Tail: nullptr" << std::endl;
            } else {
                std::cout << "Tail: " << tail->value << std::endl;
            }
        };
        void getLength() {
            std::cout << "Length: " << length << std::endl;
        };
        void __str__() {};
        void make_empty() {};
        void append(int value) {
            Node* node = new Node(value);
            if (length == 0) {
                head = node;
                tail = node;
            }
            else {
                tail->next  = node;
                tail        = node;
            }
            length++;

        };
        void pop() {
            if (length == 0) return;
            Node* cur = head;
            Node* nex = head;
            while (nex->next) {
                cur = nex;
                nex = nex->next;
            }
            tail = cur;
            tail->next = nullptr;
            length--;
            if (length == 0) {
                head = nullptr;
                tail = nullptr;
            }
            delete nex;
        };
        void prepend(int value) {
            Node* node = new Node(value);
            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                node->next = head;
                head = node;
            }
            length++;
        }
        void pop_first() {
            if (length==0) return;
            Node* temp = head;
            if (length==1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = temp->next;
            }
            delete temp;
            length--;
        };
        bool check_index(int index) {
            if (index < 0 || index >= length) {
                return false;
            }
            return true;
        }
        Node* get(int index) {
            if (!check_index(index)) return nullptr;
            if (length == 0) return nullptr;
            Node* temp = head;
            for (int i=0; i<index; i++) {
                temp = temp->next;
            }
            return temp;
        }
        bool set(int index, int value) {
            Node* node = get(index);
            if (node) {
                node->value = value;
                return true;
                }
            else return false;
            
        }
        bool insert(int index, int value) {
            if (!check_index(index)) return false;
            if (index==0) {
                prepend(value);
                return true;
            } if (index == length) {
                append(value);
                return true;
            } 
            else {
                Node* node = new Node(value);
                Node* temp = get(index-1);
                node->next = temp->next;
                temp->next = node;
                length++;
                return true;
            }


        };
        void remove(int index) {
            std::cout << "remove index: " << index << std::endl;
            std::cout << "length: " << length << std::endl;
            if (!check_index(index)) return;
            if (index==0) return pop_first();
            if (index==length-1) return pop();
            Node* prev = get(index-1);
            Node* node = prev->next;
            prev->next = node->next;
            delete node;
            length--;
        
        };
        void reverse() {
            Node* node = head;
            head = tail;
            tail = node;
            Node* prev = nullptr;
            Node* next = node->next;
            for (int i=0; i<length; i++) {
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
        };


};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->printList();
    myLinkedList->reverse();
    myLinkedList->printList();
    delete myLinkedList;
    return 0;
};