
/**
========================================================================
Stacks & Queues

STACK: LIFO:    Implement a stack using a linked list.
                Using position 0 in a linked list we achieve:
                    add:    O(1)
                    remove: O(1)

QUEUE: FIFO:    Implement a queue using a linked list.
                    add:    O(1)
                    remove: O(1)
      
: zach wolpe
: zach.wolpe@medibio.com.au
: 02 July 2023
========================================================================
*/

#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next  = nullptr;
        }
};

class Stack  {
    private:
        Node* top;
        int height;
    
    public:
        Stack(int value) {
            Node* node = new Node(value);
            top = node;
            int height = 1;
        }

        ~Stack() {
            Node* node = top;
            while (top) {
                top = top->next;
                delete node;
                node = top;
            }
        };

        void printData() {
            if (height) {
                Node* first = this->top;
                std::cout << "Stack : [";
                while (first) {
                    std::cout << "(" << first->value << ")";
                    if (first->next) std::cout << "->";
                    first = first->next;
                }
                std::cout << "]" << std::endl;
            }
        }

        void getTop() {
            if (top == nullptr) {
                std::cout << "Top: nullptr" << std::endl;
            }   else {
                std::cout << "Top: " << top->value << std::endl;
            }
        }

        void push(int value) {
            Node* node = new Node(value);
            node->next = top;
            top = node;
            height++;
        }

        int pop() {
            if (height == 0) return INT_MIN;
            Node* node = top;
            top = node->next;
            int pop_value = node->value;
            delete node;
            height--;
            return pop_value;
        }

        Node* pop_node() {
            if (height ==  0) return nullptr;
            Node* node = top;
            top = node->next;
            node->next = nullptr;
            return node;
        }


};



class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    
    public:
        Queue(int value) {
            Node* node = new Node(value);
            this->first = node;
            this->last  = node;
            length = 1;
        }

        ~Queue() {
            // default destructor does not remove nodes.
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printData() {
            if (length) {
                Node* first = this->first;
                std::cout << "Stack : [";
                while (first) {
                    std::cout << "(" << first->value << ")";
                    if (first->next) std::cout << "->";
                    first = first->next;
                }
                std::cout << "]" << std::endl;
            }
        }

        void enqueue(int value) {
            Node* node = new Node(value);
            if (length == 0) {
                first = node;
                last  = node;
            } else {
                last->next = node;
                last = node; 
            }
            length++;
        }

        int dequeue() {
            if (length == 0) return INT_MIN;
            Node* node = first;
            int node_value = node->value;
            if (length == 1) {
                first = nullptr;
                last  = nullptr;
            } else first = node->next;
            length--;
            delete node;
            return node_value;
        }
};



int main() {
        
    Stack* stack = new Stack(19);
    stack->push(13);
    stack->printData();
    std::cout << "Pop: " << stack->pop();
    std::cout << "Pop: " << stack->pop();

    Queue* queue = new Queue(44);
    queue->enqueue(3);
    queue->enqueue(12);
    queue->enqueue(-64);


    queue->printData();
    std::cout << queue->dequeue() << std::endl;

            
}  
