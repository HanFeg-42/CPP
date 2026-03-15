#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <sstream>

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

int toInt(std::string& s)
{

}
double toDouble(std::string& s)
{

}
float toFloat(std::string& s)
{

}
char toChar(std::string& s)
{

}

void ScalarConverter::convert(std::string literal)
{
    toChar(literal);
    toInt(literal);
    toFloat(literal);
    toDouble(literal);
}

ScalarConverter::~ScalarConverter() {}