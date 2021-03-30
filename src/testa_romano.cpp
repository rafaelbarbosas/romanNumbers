// Copyright 2021 Rafael Barbosa de Sousa -170043827

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/romano.h"

using std::cout;

TEST_CASE("Testing basic numbers", "[catch]") {
    REQUIRE(roman_to_decimal("I") == 1);
    REQUIRE(roman_to_decimal("V") == 5);
    REQUIRE(roman_to_decimal("X") == 10);
    REQUIRE(roman_to_decimal("L") == 50);
    REQUIRE(roman_to_decimal("C") == 100);
    REQUIRE(roman_to_decimal("D") == 500);
    REQUIRE(roman_to_decimal("M") == 1000);
}
