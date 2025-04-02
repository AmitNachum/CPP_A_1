#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;



TEST_CASE("Prim's Algorithm on Disconnected Graph") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(2, 3, 1);  

    
    CHECK_THROWS_WITH(Algorithms::primsAlgorithm(&g), "Graph is not connected");
}


TEST_CASE("Check Graph Connectivity") {
     Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    CHECK(Algorithms::isConnectedGraph(&g, 0) == true);

    //disconnected
     Graph g2(5);
    g2.addEdge(0, 1, 1);
    g2.addEdge(2, 3, 1); 

    CHECK(Algorithms::isConnectedGraph(&g2, 0) == false);
}


TEST_CASE("BFS and DFS Traversal") {
    Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    std::ostringstream out;

    SUBCASE("BFS Traversal") {
        Algorithms::bfs(&g, 0);
        CHECK(true); // No assertion, just testing for successful traversal.
    }
    std::cout << "\n";

    SUBCASE("DFS Traversal") {
        Algorithms::dfs(&g, 0);
        CHECK(true); // No assertion, just testing for successful traversal.
    }
}


TEST_CASE("Kruskal's Algorithm") {
    Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    Graph *MST = Algorithms::kruskalsAlgorithm(&g);
    CHECK(MST != nullptr);
    delete MST;
}

TEST_CASE("Prim's Algorithm") {
    Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    Graph *MST = Algorithms::primsAlgorithm(&g);
    CHECK(MST != nullptr);
    delete MST;
}

TEST_CASE("Dijkstra's Algorithm") {
    Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    Graph *SPT = Algorithms::dijkstraAlgorithm(&g, 0);
    CHECK(SPT != nullptr);
    delete SPT;
}

TEST_CASE("Negative Edges in Dijkstra's Algorithm") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, -1); // negative edge
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // Check if std::invalid_argument is thrown
    CHECK_THROWS(Algorithms::dijkstraAlgorithm(&g, 0));
}

