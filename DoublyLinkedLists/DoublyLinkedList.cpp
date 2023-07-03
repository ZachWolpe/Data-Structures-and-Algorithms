
/**
========================================================================
Doubly Linked List

An extention of a linked list, where each node has a pointer to the next and previous node.

BigO
    - append    (add item end):             O(1)      
    - Prepend   (add item front):           O(1)
    - Pop       (remove item end):          O(1)    
    - Pop First (remove item front):        O(1)
    - get       (fetch item from list):     O(n/2)
    - Insert    (add item middle):          O(n/2)  
    - Remove    (remove item middle):   
    - lookup by value:                                
    - lookup by index:                  
      
: zach wolpe
: zach.wolpe@medibio.com.au
: 01 July 2023
========================================================================
*/

#include <iostream>

class Node {
public:
    int value;
    Node *next;
    Node *prev;
    Node (int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* node = new Node(value);
        this->head = node;
        this->tail = node;
        this->length = 1;
    }
    ~DoublyLinkedList() {
        // Destructor:
        // The Node is not removed from memory by default.
        // Only the `this` properties are removed. Head, tail and length are all deleted by the default destructor.
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
    }}

    void printData() {
        Node* temp = head;
        std::cout << "DLL: ";
        while (temp) {
            std::cout << '(' << temp->value << ')';
            if (temp->next != nullptr) {
                std::cout << "->";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
        }

    void getHead() {
        if (head == nullptr) std::cout << "Head: nullptr" << std::endl;
        else std::cout << "Head: " << head->value << std::endl;
        }
    
    void getTail() {
        if (tail == nullptr) std::cout << "Tail: nullptr" << std::endl;
        else std::cout << "Tail: " << tail->value << std::endl;
    }

    void getLen() {std::cout << "Length: " << length << std::endl;};

    void append(int value) {
        Node* node = new Node(value);
        if (length == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        length++;
    }
    
    void deleteLast() {
        if (length == 0) return;
        Node* node = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        delete node;
        length --;

    }

    void prepend(int value) {
        Node* node = new Node(value);
        if (length == 0) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* node = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else { 
            head = head->next;
            head-> prev = nullptr;
        }
        delete node;
        length--;

    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if (index < length/2) {
            // first half
            for (int i=0; i!=index; i++) temp = temp->next;
        } else {
            temp = tail;
            for (int i=length; i!=index; i--) temp = temp->prev;
        }
        return temp;
    }
    
    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
        }   

    bool insert(int index, int value) {
        if (index < 0 || index >= length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        };
        if (index == length) {
            append(value);
            return true;
        }
        Node* node = new Node(value);
        Node* temp = get(index-1);
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        length++;
        return true;

    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length-1) return deleteLast();
        Node* temp = get(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
    }
};






int main() {
    DoublyLinkedList* dll = new DoublyLinkedList(23);
    dll->getHead();
    dll->getTail();
    dll->getLen();
    dll->append(44);
    dll->append(3);
    dll->printData();
    dll->deleteLast();
    dll->printData();
    dll->deleteLast();
    dll->printData();
    
    dll->prepend(12);
    dll->printData();
    // dll->deleteFirst();

    dll->printData();
    Node* x = dll->get(0);
    std::cout << x << std::endl;
    if (x != nullptr) std::cout << x->value << std::endl;
    dll->set(0, 404);
    dll->printData();
    dll->insert(1,666);
    dll->printData();
    dll->deleteNode(1);
    dll->printData();



}