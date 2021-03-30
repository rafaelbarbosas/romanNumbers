// Copyright 2021 Rafael Barbosa de Sousa -170043827

#include "../include/romano.h"

int get_basic_value(char const roman_char) {
    if (roman_char == 'I')
        return 1;
    if (roman_char == 'V')
        return 5;
    if (roman_char == 'X')
        return 10;
    if (roman_char == 'L')
        return 50;
    if (roman_char == 'C')
        return 100;
    if (roman_char == 'D')
        return 500;
    if (roman_char == 'M')
        return 1000;

    return -1;
}

int roman_to_decimal(char const *roman_number) {
    return get_basic_value(roman_number[0]);
}
