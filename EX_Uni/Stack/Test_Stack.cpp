#include "stk.hpp"
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("Testing Stack Operations"){

    stk st;

    SUBCASE("Push and Peek Operations"){
        st.push(10);
        st.push(20);
        st.push(30);

        CHECK(st.peek() == 30);
    }

    SUBCASE("Push and Pop operations"){
        st.push(1);
        st.push(2);
        st.push(3);

        st.pop();
        CHECK(st.peek() == 2);

        st.pop();
        CHECK(st.peek() == 1);

        st.pop();

        CHECK(st.isEmpty() == true);
    }



    SUBCASE("Dynamic resizing the stack"){
        for (size_t i = 0; i < 150; i++)
        {
            st.push(i);
        }

        CHECK(st.peek() == 149);
        CHECK(st.isEmpty() == false);
        
    }
}