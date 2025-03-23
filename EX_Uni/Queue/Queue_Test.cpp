#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Queue.hpp"

TEST_CASE("Queue Operations"){
    Queue q;

    SUBCASE("Offer and Peek"){
        q.offer(10);
        q.offer(20);
        q.offer(30);

        CHECK(q.peek() == 10);
    }

    SUBCASE("Poll operation"){
        q.offer(1);
        q.offer(2);

        CHECK(q.poll() == 1);
        CHECK(q.poll() == 2);
        CHECK(q.isEmpty() == true);
    }

    SUBCASE("Dynamic resizing"){
        for (int i = 0; i < 150; ++i) {
            q.offer(i);
        }

        CHECK(q.size() == 150);
        CHECK(q.peek() == 0);
    }

    SUBCASE("Mixing operations"){
        q.offer(5);
        q.offer(15);
        q.poll();
        q.offer(25);
        q.offer(35);

        CHECK(q.peek() == 15);
        CHECK(q.size() == 3);
    }
}
