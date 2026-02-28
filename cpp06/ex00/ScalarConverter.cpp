#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other)
{
    (void)other;
    return *this;
}

char getType(std::string& s)
{
    (void)s;
    return 'i';
}

void printScalarTypes(double n)
{
    std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << n << std::endl;
}

int ft_stoi(std::string& s)
{
    char* endptr;
    long number = std::strtol(s.c_str(), &endptr, 10); // Base 10 conversion
    return static_cast<int>(number);
}
double ft_stod(std::string& s)
{
    char* end_ptr;
    double value = std::strtod(s.c_str(), &end_ptr);
    return value;
}
float ft_stof(std::string& s)
{
    char* end_ptr;
    double value = std::strtod(s.c_str(), &end_ptr);
    return static_cast<float>(value);
}
char ft_stoc(std::string& s)
{
    char* endptr;
    long number = std::strtol(s.c_str(), &endptr, 10); // Base 10 conversion
    return static_cast<char>(number);
}

void ScalarConverter::convert(std::string literal)
{
    char type = getType(literal);
    switch (type)
    {
    case 'i':
        printScalarTypes(ft_stoi(literal));
        break;
    case 'd':
        printScalarTypes(ft_stod(literal));
        break;
    case 'f':
        printScalarTypes(ft_stof(literal));
        break;
    case 'c':
        printScalarTypes(ft_stoc(literal));
        break;
    default:
        break;
    }
}

ScalarConverter::~ScalarConverter() {}