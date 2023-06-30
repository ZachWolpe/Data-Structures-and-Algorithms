
"""
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
"""


class Node:
    def __init__(self, value, next=None) -> None:
        self.value      = value
        self.next       = next


        
class LinkedList:
    def __init__(self, value):
        node        = Node(value)
        self.head   = node
        self.tail   = node
        self.length = 1 

    def print_list(self):
        temp = self.head
        i = 0
        while temp is not None:
            print(f' ->', temp.value, end='\n')
            # print(f' node {i}(', temp.value, ')->', sep='', end='')
            temp = temp.next
            i += 1
        print()
    
    def __str__(self) -> str:
        return 'Head: ' + str(self.head.value)
    
    def make_empty(self):
        self.head = None
        self.tail = None
        self.length = 0

    def append(self, value):
        node = Node(value)
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            self.tail.next  = node
            self.tail       = node
        self.length += 1
        return True


    def pop(self):
        if self.length == 0:
            return None
        cur = self.head
        nxt = self.head
        while(nxt.next):
            cur = nxt
            nxt = nxt.next
        self.tail       = cur
        self.tail.next  = None
        self.length    -= 1
        if self.length == 0:
            self.head = None
            self.tail = None
        return nxt
        


    def prepend(self, value):
        node = Node(value)
        # case 1: no nodes
        if not self.length:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.length += 1
        return True
        
            
        # case 2: 

    def pop_first(self):
        if self.length == 0:
            return None
        cur          = self.head
        self.head    = self.head.next
        cur.next     = None
        self.length -= 1
        if self.length == 0:
            self.tail = None
        return cur


    # def set_value(self, index, value):
    #     if index < 0 or index >= self.length:
    #         return None
    #     prv = self.head
    #     for _ in range(index-1):
    #         prv = prv.next
    #     node = Node(value)
    #     if prv.next is not None:
    #         node.next = prv.next.next
    #     else:
    #         node.next = None
    #     prv.next  = node 

    def get(self, index):
        if index < 0 or index >= self.length:
            return None
        temp = self.head
        for _ in range(index):
            temp = temp.next
        return temp
        

    def set_value(self, index, value):
        # better solution
        temp = self.get(index)
        if temp:
            temp.value = value
            return True
        return False


    def check_index(self, index):
        if index < 0 or index >= self.length:
            return False
        else:
            return True
        
            
    # def insert(self, index, value):
    #     if not self.check_index(index):
    #         return
    #     node = Node(value)
    #     if index == 0:
    #         node.next = self.head
    #         self.head = node
    #         return
    #     prv = self.head
    #     cur = prv.next
    #     for _ in range(index-1):
    #         prv = cur
    #         cur = cur.next
    #     prv.next    = node
    #     node.next   = cur
    #     self.length += 1

    def insert(self, index, value):
        # better solution
        if index <0 or index >= self.length:
            return False
        if index == 0:
            return self.prepend(value)
        if index == self.length:
            return self.append(value)
        node = Node(value)
        temp = self.get(index-1)
        node.next = temp.next
        temp.next = node
        self.length += 1


    
    def remove(self, index):
        if index < 0 or index >= self.length:
            return None
        if index == 0:
            return self.pop_first()
        if index == self.length - 1:
            print('the')
            return self.pop()
        else:
            prv = self.get(index-1)
            cur = prv.next
            prv.next = cur.next
            cur.next = None
            self.length -= 1
            return cur
        

            
    def reverse(self):
        temp        = self.head
        self.head   = self.tail
        self.tail   = temp
        after       = temp.next
        before      = None
        for _ in range(self.length):
            after       = temp.next
            temp.next   = before
            before      = temp
            temp        = after





if __name__ == '__main__':

    linked_list = LinkedList(11)
    linked_list.append(3)
    linked_list.append(23)
    linked_list.append(7)

    linked_list.print_list()
    linked_list.reverse()
    linked_list.print_list()







 