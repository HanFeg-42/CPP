#pragma once

#include <iostream>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
public:
	class InvalidArgException : public std::exception {
	public:
		const char* what() const throw();
	};
	class InvalidConversionException : public std::exception {
	public:
		const char* what() const throw();
	};
    static void convert(std::string literal);
    ~ScalarConverter();
};
