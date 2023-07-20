"""
========================================================================
@file graphs.cpp

Big O
------

Space Complexity:
    Let 
        V := number of vertices
        E := number of edges

    Adjacent  matrix:   O(|V|^2)
    Adjacency list:     O(|V|+|E|)

Time Complexity:
    Add Vertex:
        Adjacent  matrix:   O(|V|^2)
        Adjacency list:     O(1)
    
    Add Edge:
        Adjacent  matrix:   O(1)
        Adjacency list:     O(1)

    Remove Edge:
        Adjacent  matrix:   O(1)
        Adjacency list:     O(1)

    Remove Vertex:
        Adjacent  matrix:   O(|V|^2)
        Adjacency list:     O(V)

: zach wolpe
: zach.wolpe@medibio.com.au
: 15 July 2023
========================================================================
"""

from abc import ABC

class Graph:
    def __init__(self):
        self.adj_list = {}

    def printGraph(self):
        for vertex in self.adj_list:
            print(vertex, ':', self.adj_list[vertex])

    def addVertex(self, vertex:str):
        if vertex not in self.adj_list.keys():
            self.adj_list[vertex] = []
            return True
        return False
    
    def addEdge(self, vertex1, vertex2):
        if (vertex1 in self.adj_list.keys() and vertex2 in self.adj_list.keys()):
            self.adj_list[vertex1].append(vertex2)
            self.adj_list[vertex2].append(vertex1)
            return True
        return False
    
    def removeEdge(self, vertex1, vertex2):
        if (vertex1 in self.adj_list.keys() and vertex2 in self.adj_list.keys()):
            try:
                self.adj_list[vertex1].remove(vertex2)
                self.adj_list[vertex2].remove(vertex1)
                return True
            except ValueError:
                pass
        return False
            
    def removeVertex(self, vertex):
        if vertex in self.adj_list.keys():
            for other_vector in self.adj_list[vertex]:
                self.adj_list[other_vector].remove(vertex)
            del self.adj_list[vertex]
        return False

    def remove_vertex(self, vertex):
        if vertex in self.adj_list.keys():
            for other_vertex in self.adj_list[vertex]:
                self.adj_list[other_vertex].remove(vertex)
            del self.adj_list[vertex]
            return True
        return False

        



if __name__ == '__main__':

    my_graph = Graph()
    my_graph.add_vertex('A')
    my_graph.add_vertex('B')
    my_graph.add_vertex('C')
    my_graph.add_vertex('D')

    my_graph.add_edge('A','B')
    my_graph.add_edge('A','C')
    my_graph.add_edge('A','D')
    my_graph.add_edge('B','D')
    my_graph.add_edge('C','D')


    print('Graph before remove_vertex():')
    my_graph.print_graph()


    my_graph.remove_vertex('D')


    print('\nGraph after remove_vertex():')
    my_graph.print_graph()



    """
    EXPECTED OUTPUT:
    ----------------
        Graph before remove_vertex():
        A : ['B', 'C', 'D']
        B : ['A', 'D']
        C : ['A', 'D']
        D : ['A', 'B', 'C']

        Graph after remove_vertex():
        A : ['B', 'C']
        B : ['A']
        C : ['A']

    """