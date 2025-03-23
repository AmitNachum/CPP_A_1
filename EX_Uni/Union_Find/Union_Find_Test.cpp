#include "Union_FInd.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("Testing Union-Find Operations") {
    Union_Find uf(10);

    SUBCASE("Initial State Check") {
        for (int i = 0; i < 10; i++) {
            CHECK(uf.find(i) == i);
        }
    }

    SUBCASE("Union Operation") {
        uf.unionNumbers(0, 1);
        uf.unionNumbers(2, 3);
        uf.unionNumbers(4, 5);

        CHECK(uf.isConnected(0, 1));
        CHECK(uf.isConnected(2, 3));
        CHECK(uf.isConnected(4, 5));
        
        CHECK(!uf.isConnected(0, 2));
        CHECK(!uf.isConnected(1, 4));
    }

    SUBCASE("Union by Rank") {
        uf.unionNumbers(0, 1);
        uf.unionNumbers(2, 3);
        uf.unionNumbers(0, 2);

        CHECK(uf.isConnected(0, 3));
        CHECK(uf.isConnected(1, 2));
    }

    SUBCASE("Path Compression Check") {
        uf.unionNumbers(0, 1);
        uf.unionNumbers(1, 2);
        uf.unionNumbers(2, 3);
        uf.unionNumbers(3, 4);

        CHECK(uf.find(4) == uf.find(0));
        
        for (int i = 0; i <= 4; i++) {
            CHECK(uf.find(i) == uf.find(0));
        }
    }

    SUBCASE("Handling Duplicate Unions") {
        uf.unionNumbers(0, 1);
        uf.unionNumbers(0, 1);

        CHECK(uf.isConnected(0, 1));
    }
}
