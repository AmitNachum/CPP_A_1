#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;

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
