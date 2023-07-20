/**
========================================================================
@file HashTable.cpp



Big O
    Note `N` is the size of the hashtable, not the number of elements in the hashtable.
    Thus O(1) is constant time, not O(N).
    - lookup:                           O(1)
    - insert:                           O(1)
    - delete:                           O(1)
    
    It is treated as O(1) because the size of the hashtable is fixed, it is theoretically possible to have a collision for every key, but this is highly unlikely.


: zach wolpe
: zach.wolpe@medibio.com.au
: 04 July 2023
========================================================================
*/

#include <iostream>
#include <vector>

class Node {
public:
    std::string key;
    int value;
    Node* next;

    Node (std::string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};


class HashTable {
private:
    static const int SIZE = 7; // static shared by all instances of class.
    Node* dataMap[SIZE];

    int hashmap(std::string key) {
        int hash = 0;
        for (int i=0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue*23) % SIZE;
        }
        return hash;
    }

public:
    // destructor
    ~HashTable() {
        for (int i=0; i>SIZE; i++) {
            Node* head = dataMap[i];
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    void printTable() {
        for (int i=0; i<SIZE; i++) {
            std::cout << i << ": " << std::endl;
            if (dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    std::cout << "  {" << temp->key <<", " << temp->value << "}" << std::endl;
                    temp = temp->next;
                }
            }
        }
    }

    void set(std::string key, int value) {
        // extract hashmap!
        int hashID = hashmap(key);
        Node* node = new Node(key, value);
        if (dataMap[hashID] == nullptr) {
            dataMap[hashID] = node;
        } else {
            Node* temp = dataMap[hashID];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    int get(std::string key) {
        int hashID = hashmap(key);
        Node* temp = dataMap[hashID];
        while (temp) {
            if (temp->key == key) return temp->value;
            else temp = temp->next;
        }
        return 0;
    };



    std::vector<std::string> keys() {
        std::vector<std::string> allKeys;
        for (int i=0; i<SIZE; i++) {
            Node* temp = dataMap[i];
            while(temp) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};



int main() {


    HashTable* htb = new HashTable();

    htb->set("nails", 100);
    htb->set("tile", 50);
    htb->set("lumber", 80);
    htb->set("bolts", 200);
    htb->set("screws", 140);

    htb->printTable();
    std::cout << " ->get(\"bolts\"): " << htb->get("bolts") << std::endl;
    
    std::vector<std::string> myKeys = htb->keys();
    for (auto key : myKeys) {
        std::cout << key << ".";
    }
    return 0;
}