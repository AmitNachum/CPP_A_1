#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Priority_Queue.hpp"

TEST_CASE("Priority Queue Test"){
    PriorityQueue pq;
    SUBCASE("Creating a Heap"){
      
      pq.insertNode(5);
      pq.insertNode(10);
      pq.insertNode(1);

      CHECK(pq.peekMin() == 1);
    }

    SUBCASE("Empty check and extract check"){
        pq.insertNode(2);
        pq.insertNode(9);
        pq.insertNode(1);

        CHECK(pq.isEmpty() == false);
        CHECK(pq.extractMin() == 1);
    }

    SUBCASE("Delete node check"){
        pq.insertNode(6);
        pq.insertNode(2);
        pq.insertNode(5);

        pq.deleteNode(2);
        CHECK(pq.peekMin() == 5);
    }
}