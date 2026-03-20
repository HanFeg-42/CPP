#pragma once

#include <iostream>

class ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
public:
	class InvalidConversionException : public std::exception {
	public:
		const char* what() const throw();
	};
    static void convert(std::string literal);
    ~ScalarConverter();
};
