#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
using namespace graph;


int main() {
    Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 3);
    g.addEdge(0, 4, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 5);
    
    
    
    

    std::cout << "BFS Traversal: ";
    Algorithms::bfs(&g, 0);
    std::cout << std::endl;

    std::cout << "DFS Traversal: ";
    Algorithms::dfs(&g, 0);
    std::cout << std::endl;


    // Testing Kruskal's Algorithm
    Graph *MST_Kruskal = Algorithms::kruskalsAlgorithm(&g);
    std::cout << "MST using Kruskal's Algorithm: ";
    MST_Kruskal->printGraph();
    std::cout << std::endl;
    delete MST_Kruskal;

    // Testing Prim's Algorithm
    Graph *MST_Prim = Algorithms::primsAlgorithm(&g);
    std::cout << "MST using Prim's Algorithm: ";
    MST_Prim->printGraph();
    std::cout << std::endl;
    delete MST_Prim;

    // Testing Dijkstra's Algorithm
    Graph *SPT_Dijkstra = Algorithms::dijkstraAlgorithm(&g, 0);
    std::cout << "Shortest Path Tree using Dijkstra's Algorithm: ";
    SPT_Dijkstra->printGraph();
    std::cout << std::endl;
    delete SPT_Dijkstra;


    

    return 0;
}
