#include "stalinsort.hpp"
#include <array>
#include <algorithm>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("Simple"){
    const auto numbers = std::array<int, 10>{1,2,3,4,5,6,7,8,9,10};
    const auto n = stalinsort(numbers.cbegin(), numbers.cend());

    REQUIRE(std::equal(n.cbegin(), n.cend(), numbers.cbegin()));
}

TEST_CASE("Unsorted"){
    const auto numbers = std::array<int, 10>{1,2,3,4,5,0,7,8,9,10};
    const auto n = stalinsort(numbers.cbegin(), numbers.cend());
    
    const auto expected = std::array<int, 9>{1,2,3,4,5,7,8,9,10};
    REQUIRE(std::equal(expected.cbegin(), expected.cend(), n.cbegin()));
}

TEST_CASE("Really unsorted"){
    const auto numbers = std::array<int, 10>{10,10,3,4,5,0,7,8,9,10};
    const auto n = stalinsort(numbers.cbegin(), numbers.cend());
    const auto expected = std::array<int, 1>{10};
    REQUIRE(std::equal(expected.cbegin(), expected.cend(), n.cbegin()));
}

TEST_CASE("std::less happy"){
    const auto numbers = std::array<int, 10>{10,9,8,7,6,5,4,3,2,1};
    const auto n = stalinsort<const int*, std::less<const int>>(numbers.cbegin(), numbers.cend());
    REQUIRE(std::equal(n.cbegin(), n.cend(), numbers.cbegin()));
}

TEST_CASE("std::less unsorted"){
    const auto numbers = std::array<int, 10>{10,9,8,7,6,7,4,3,2,1};
    const auto n = stalinsort<const int*, std::less<const int>>(numbers.cbegin(), numbers.cend());
    const auto expected = std::array<int, 9>{10,9,8,7,6,4,3,2,1};
    REQUIRE(std::equal(expected.cbegin(), expected.cend(), n.cbegin()));
}
