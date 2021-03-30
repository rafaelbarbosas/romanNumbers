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

bool is_valid(std::string roman_number) {
    return std::regex_match(roman_number, std::regex(
        "M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$"));
}

int roman_to_decimal(std::string roman_number) {
    if (!is_valid(roman_number) )
        return -1;

    int result = 0;
    for (int i = 0; i < roman_number.length(); i++) {
        int current_value = get_basic_value(roman_number[i]);
        if ( i < roman_number.length() - 1 ) {  // if has next value
            int next_value = get_basic_value(roman_number[i + 1]);
            if (current_value >= next_value) {
                result += current_value;
            } else {
                result += next_value - current_value;
                i++;
            }
        } else {
            result += current_value;
        }
    }

    if ( result > 3000)
        return -1;

    return result;
}
