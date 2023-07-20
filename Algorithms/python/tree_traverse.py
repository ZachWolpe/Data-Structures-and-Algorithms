"""
========================================================================
@file tree_traverse.py

Traversal of a Binary Search Tree.

Big O:
    Space Complexity:
    Time Complexity:

: zach wolpe
: zach.wolpe@medibio.com.au
: 18 July 2023
========================================================================
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        
class BinarySearchTree:
    def __init__(self) -> None:
        self.root = None
    
    def insert(self, value):
        node = Node(value)
        if self.root == None:
            self.root = node
            return self
        temp = self.root
        while True:
            if node.value == temp.value:
                return None
            if node.value < temp.value:
                if temp.left is None:
                    temp.left = node
                    return self
                temp = temp.left
            else:
                if temp.right is None:
                    temp.right = node
                    return self
                temp = temp.right
        
    def find(self, value):
        if self.root == None:
            return False
        temp = self.root
        while True:
            if temp == None:
                return False
            if temp.value == value:
                return True
            if value < temp.value:
                temp = temp.left
            else:
                temp = temp.right
    


class TreeTraversal(BinarySearchTree):
    def __init__(self) -> None:
        super().__init__()

    def BFS(self):
        """
        Breadth First Search
        """
        node = self.root
        queue = []
        visited = []
        queue.append(node)
        while len(queue) > 0:
            node = queue.pop(0)
            visited.append(node.value)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return visited
    
    @staticmethod
    def traverse(node, visited, method):
        if method == 'preorder': visited.append(node.value)
        if node.left:
            TreeTraversal.traverse(node.left, visited, method)
        if method == 'inorder': visited.append(node.value)
        if node.right:
            TreeTraversal.traverse(node.right, visited, method)
        if method == 'postorder': visited.append(node.value)
        return visited
    
    def DFS(self, method='preorder'):
        if method not in ['preorder', 'postorder', 'inorder']:
            raise Exception('Invalid method specified')
        return TreeTraversal.traverse(self.root, [], method)


if __name__ == '__main__':
    tree = TreeTraversal()
    tree.insert(47)\
        .insert(21)\
        .insert(76)\
        .insert(18)\
        .insert(27)\
        .insert(52)\
        .insert(82)

    print(tree.BFS())
    print(tree.DFS('preorder'))
    print(tree.DFS('inorder'))
    print(tree.DFS('postorder'))


