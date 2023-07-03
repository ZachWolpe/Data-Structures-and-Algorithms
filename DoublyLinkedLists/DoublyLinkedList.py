
"""
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
========================================================================
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self, value) -> None:
        node = Node(value)
        self.head = node
        self.tail = node
        self.length = 1

    def __str__(self) -> str:
        temp = self.head
        msg = '---'*20
        if temp is None:
            return "Empty Doubly Linked List."
        while temp:
            msg += '\n' + str(temp) + ' -> ' + str(temp.value)
            temp = temp.next
        return msg

    def append(self, value) -> bool:
        node = Node(value)
        # if no nodes
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
        self.length += 1
        return True

    def pop(self) -> Node:
        if self.length == 0:
            return None
        node = self.tail
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.tail       = self.tail.prev
            self.tail.next  = None
            node.prev       = None
        self.length -= 1
        return node
    
    def prepend(self, value) -> bool:
        node = Node(value)
        if self.length == 0:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node
        self.length += 1
        return True

    def popfist(self) -> Node:
        if self.length == 0:
            return
        node = self.head
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
            node.next = None
        self.length -= 1
        return node

    def get(self, index) -> Node:
        if index < 0 or index >= self.length:
            return None
        if index < self.length/2:
            # first half
            node = self.head
            for _ in range(index):
                node = node.next
        else:
            # second half
            node = self.tail
            for _ in range(self.length-1, index, -1):
                node = node.prev
        return node
    
        
    def set_value(self, index, value) -> bool:
        node = self.get(index)
        if node:
            node.value = value
            return True
        return False
    
    def insert(self, index, value) -> bool:
        if index < 0 or index > self.length:
            return False
        if index == 0:
            return self.prepend(value)
        if index == self.length:
            return self.append(value)
        else:
            newn  = Node(value)
            node = self.get(index)
            prev = node.prev
            newn.prev = prev
            prev.next = newn
            node.prev = newn
            newn.next = node
            self.length += 1
            return True


    def remove(self, index) -> bool:
        if index < 0 or index >= self.length:
            return False
        if index == 0:
            return self.popfist()
        if index == self.length-1:
            return self.pop()
        node = self.get(index)
        node.prev.next = node.next
        node.next.prev = node.prev
        node.prev = None
        node.next = None
        self.length -= 1
        return node

        


if __name__ == '__main__':
    myDoublyLinkedList = DoublyLinkedList(1)
    myDoublyLinkedList.append(3)
    myDoublyLinkedList.insert(1,2)
    myDoublyLinkedList.insert(3,4)
    print(myDoublyLinkedList)
    myDoublyLinkedList.remove(1)
    myDoublyLinkedList.remove(2)




    # print(myDoublyLinkedList)
    # myDoublyLinkedList.pop()
    # print(myDoublyLinkedList)
    # myDoublyLinkedList.append(2)
    # myDoublyLinkedList.prepend(0)
    # print(myDoublyLinkedList)
    # myDoublyLinkedList.set_value(0, 134)
    # myDoublyLinkedList.set_value(99, 99999)
    # myDoublyLinkedList.set_value(2, 99999)
    # myDoublyLinkedList.insert(1,66666)
    # myDoublyLinkedList.insert(1,-800)

    # print('.get(0) ', myDoublyLinkedList.get(0).value)
    # print('.get(1) ', myDoublyLinkedList.get(1).value)
    # print('.get(2) ', myDoublyLinkedList.get(2).value)
    # print('popfirst(): ', myDoublyLinkedList.popfist())
    # print(myDoublyLinkedList)
    # print('popfirst(): ', myDoublyLinkedList.popfist())
    # print(myDoublyLinkedList)
    # print('popfirst(): ', myDoublyLinkedList.popfist())
    # print(myDoublyLinkedList)
    # print('popfirst(): ', myDoublyLinkedList.popfist())
    print(myDoublyLinkedList)



