

"""
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
: 30 June 2023
========================================================================
"""

class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.next  = None

class Stack:
    def __init__(self, value) -> None:
        node = Node(value)
        self.top    = node
        self.height = 1

    def __str__(self) -> str:
        msg = '\nStack: ['
        node = self.top
        while node:
            msg += str(node.value) + ','
            node = node.next
        if self.height > 0:
            msg = msg[:-1]
        msg += ']'
        return msg
    
    def push(self, value) -> None:
        node = Node(value)
        if self.height == 0:
            self.top = node
        else:
            node.next = self.top
            self.top = node
        self.height += 1
        
    def pop(self) -> Node:
        if self.height == 0:
            return None
        node = self.top
        self.top = self.top.next
        node.next = None
        self.height -= 1
        return node


class Queue:
    def __init__(self, value) -> None:
        node = Node(value)
        self.first  = node
        self.last   = node
        self.length = 1
    
    def __str__(self) -> str:
        msg = '\nQueue: ['
        node = self.first
        while node:
            msg += str(node.value) + ','
            node = node.next
        if self.length > 0:
            msg = msg[:-1]
        msg += ']'
        return msg

    def enqueue(self, value) -> None:
        node = Node(value)
        if self.length == 0:
            self.first = node
            self.last  = node
        else:
            self.last.next = node
            self.last = node
        self.length += 1

    def dequeue(self) -> Node:
        if self.length == 0:
            return None
        node = self.first
        if self.length == 1:
            self.first = None
            self.last  = None
        else:
            self.first = self.first.next
            node.next = None
        self.length -= 1
        return node


if __name__ == '__main__':
    queue = Queue(1)
    queue.enqueue(22)
    print(queue)
    print('dequeue: ', queue.dequeue().value)
    print(queue)
    queue.dequeue()
    print(queue)
    queue.dequeue()
    print(queue)


    # stack = Stack(2)
    # stack.push(11)
    # stack.push(22)
    # stack.push(33)
    # print(stack)
    # stack.pop()
    # print(stack)
    # stack.pop()
    # stack.pop()
    # stack.pop()
    # print(stack)

