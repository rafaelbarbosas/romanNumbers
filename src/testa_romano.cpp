// Copyright 2021 Rafael Barbosa de Sousa -170043827

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/romano.h"

TEST_CASE("Testing basic numbers", "[basic]") {
    REQUIRE(roman_to_decimal("I") == 1);
    REQUIRE(roman_to_decimal("V") == 5);
    REQUIRE(roman_to_decimal("X") == 10);
    REQUIRE(roman_to_decimal("L") == 50);
    REQUIRE(roman_to_decimal("C") == 100);
    REQUIRE(roman_to_decimal("D") == 500);
    REQUIRE(roman_to_decimal("M") == 1000);
}

TEST_CASE("Testing invalid numbers", "[ivalid]") {
    REQUIRE(roman_to_decimal("IIII") == -1);
    REQUIRE(roman_to_decimal("XXXX") == -1);
    REQUIRE(roman_to_decimal("VX") == -1);
    REQUIRE(roman_to_decimal("IIX") == -1);
    REQUIRE(roman_to_decimal("LM") == -1);
    REQUIRE(roman_to_decimal("IM") == -1);
}

TEST_CASE("Testing valid numbers - 1 to 10", "[valid-1-10]") {
    REQUIRE(roman_to_decimal("I") == 1);
    REQUIRE(roman_to_decimal("II") == 2);
    REQUIRE(roman_to_decimal("III") == 3);
    REQUIRE(roman_to_decimal("IV") == 4);
    REQUIRE(roman_to_decimal("V") == 5);
    REQUIRE(roman_to_decimal("VI") == 6);
    REQUIRE(roman_to_decimal("VII") == 7);
    REQUIRE(roman_to_decimal("VIII") == 8);
    REQUIRE(roman_to_decimal("IX") == 9);
    REQUIRE(roman_to_decimal("X") == 10);
}

TEST_CASE("Testing valid numbers - edges", "[valid-edges]") {
    REQUIRE(roman_to_decimal("IV") == 4);
    REQUIRE(roman_to_decimal("IX") == 9);
    REQUIRE(roman_to_decimal("XL") == 40);
    REQUIRE(roman_to_decimal("XC") == 90);
    REQUIRE(roman_to_decimal("CD") == 400);
    REQUIRE(roman_to_decimal("CM") == 900);
}

TEST_CASE("Testing valid max numbers", "[valid-max]") {
    REQUIRE(roman_to_decimal("MMCMXCIX") == 2999);
    REQUIRE(roman_to_decimal("MMCMXCVIII") == 2998);
    REQUIRE(roman_to_decimal("MMCMXCVII") == 2997);
    REQUIRE(roman_to_decimal("MMM") == 3000);
}

TEST_CASE("Testing invalid max numbers", "[invalid-max]") {
    REQUIRE(roman_to_decimal("MMMI") == -1);
    REQUIRE(roman_to_decimal("MMMII") == -2);
}
