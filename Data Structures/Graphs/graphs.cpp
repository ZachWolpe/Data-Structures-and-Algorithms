/**
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
: 04 July 2023
========================================================================
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    std::unordered_map< std::string, std::unordered_set<std::string> > adjList;

public:
    void printGraph() {
        std::unordered_map< std::string, std::unordered_set<std::string> >::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end()) {
            std::cout << kvPair->first << ": [ ";
            std::unordered_set<std::string>::iterator edge = kvPair->second.begin();
            while (edge != kvPair->second.end()) {
                std::cout << edge->data() << " "; // view edges
                edge++;
            }
            std::cout << "]" << std::endl;
            kvPair++;
        }
    }
    
    bool addVertex(std::string vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex];
            return true;
        }
        return false;
    };

    bool addEdge(std::string vertex1, std::string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    };

    bool removeEdge(std::string vertex1, std::string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    };

    bool removeVertex(std::string vertex) {
        if (adjList.count(vertex) == 0) return false;
        for (auto otherVertex : adjList.at(vertex)) {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    };
};

int main() {
    std::cout << "\n\n< DevTools :/ " << std::endl;

    Graph* graph = new Graph();
    graph->addVertex("A");
    graph->addVertex("B");
    std::cout << "Graph:\n";
    graph->printGraph();

    std::cout << "........................." << std::endl; 
    std::cout << "Graph before addEdge(): \n";
    graph->printGraph();
    graph->addEdge("A", "B");
    std::cout << "\n\nGraph after addEdge(): \n";
    graph->printGraph();

    return 0;
}