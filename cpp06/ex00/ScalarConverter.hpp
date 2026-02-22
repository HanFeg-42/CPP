#pragma once

#include <iostream>

class ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter& const other);
    ScalarConverter& operator=(ScalarConverter& const other);
public:
    static void convert(std::string literal);
    ~ScalarConverter();
};
