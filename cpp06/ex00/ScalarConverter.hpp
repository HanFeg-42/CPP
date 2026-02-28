#pragma once

#include <iostream>

class ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
public:
    static void convert(std::string literal);
    ~ScalarConverter();
};
