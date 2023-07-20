"""
========================================================================
@file HashTable.py

Big O
    Note `N` is the size of the hashtable, not the number of elements in the hashtable.
    Thus O(1) is constant time, not O(N).
    - lookup:                           O(1)
    - insert:                           O(1)
    - delete:                           O(1)
    
    It is treated as O(1) because the size of the hashtable is fixed, it is theoretically possible to have a collision for every key, but this is highly unlikely.


: zach wolpe
: zach.wolpe@medibio.com.au
: 18 July 2023
========================================================================
"""

class HashTable:
    def __init__(self, size=7) -> None:
        self.map = [None] * size
    
    def __hash(self, key):
        hash = 0
        for letter in key:
            hash = (hash + ord(letter) * 44) % len(self.map)
        return hash
    
    def __str__(self) -> str:
        for i, val in enumerate(self.map):
            print(i, val)
        return ''
    
    def set_item(self, key, value):
        idx = self.__hash(key)
        if self.map[idx] is None:
            self.map[idx] = []
        self.map[idx].append([key, value])
    

    def get_item(self, key):
        idx = self.__hash(key)
        if self.map[idx] is not None:
            for i in range(len(self.map[idx])):
                if self.map[idx][i][0] == key:
                    return self.map[idx][i][1]
        return None
    
    def keys(self):
        keys = []
        for i in range(len(self.map)):
            if self.map[i]:
                for j in range(len(self.map[i])):
                    keys.append(self.map[i][j][0])
        return keys
    



if __name__ == '__main__':
    hashmap = HashTable()
    hashmap.set_item('a', 1)
    hashmap.set_item('b', 2)
    hashmap.set_item('c', 3)
    hashmap.set_item('d', 4)

    print(hashmap.get_item('a'))
    print(hashmap.get_item('b'))
    print(hashmap.get_item('c'))