#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

#define INF 100000000

namespace graph {


struct Node {
    int vertex;       
    int weight;       
    Node* next;       

    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {} 
};

class Graph {
private:
    int vertexAmount;     
    Node** adjList;  
      

    
    void expandGraph(int newAmount);
    
public:
    Graph(int vertexAmount);
    Graph(Graph *other);
    ~Graph();

    bool isWithinBounds(int vertex) const;
    void addEdge(int u, int v, int weight);   
    void removeEdge(int u, int v);            
    void printGraph();                        
    Node** getAdj();                          
    int getVerAmount() const;                 
};

}

#endif
