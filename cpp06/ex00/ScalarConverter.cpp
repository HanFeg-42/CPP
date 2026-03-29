#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <sstream>

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other)
{
    (void)other;
    return *this;
}

const char* ScalarConverter::InvalidConversionException::what() const throw()
{
	return "Invalid Conversion!";
}

const char* ScalarConverter::InvalidArgException::what() const throw()
{
	return "Usage: ./convert [number]";
}

int isPseudoLiteral(std::string& s)
{
    return (s == "-inff" || s == "+inff" || s == "nanf"
            || s == "nan" || s == "-inf" || s == "+inf");
}

char getType(std::string& s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return FLOAT;
    if (s == "nan" || s == "-inf" || s == "+inf")
        return DOUBLE;
    if (s.length() == 1 && !isdigit(s[0]))
        return CHAR;
    return INT;
}

void toInt(double val, std::string& s)
{
    if (isPseudoLiteral(s))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(val) << "\n";
}

void toDouble(double val, int type, std::string s)
{
    if (isPseudoLiteral(s))
    {
        if (type == DOUBLE)
            std::cout << "double: " << s << "\n";
        else
            std::cout << "double: " << s.substr(0, s.size() - 1) << "\n";
        return ;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << val << "\n";
}

void toFloat(double val, int type, std::string s)
{
    if (isPseudoLiteral(s))
    {
        if (type == FLOAT)
            std::cout << "float: " << s << "\n";
        else
            std::cout << "float: " << s << "f\n";
        return ;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f\n";

}

void toChar(double val, std::string& s)
{
    if (isPseudoLiteral(s))
        std::cout << "char: impossible\n";
    else if (val > 126 || val < 32)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(val) << "'\n";

}

void ScalarConverter::convert(std::string literal)
{
    std::stringstream ss(literal);
    double value = 0.0;
    char c;
    
    int type = getType(literal);
    if (!isPseudoLiteral(literal) && type != CHAR)  // type == INT
    {
        ss >> value;
        if (ss.fail() || (ss >> c && c != 'f') || ss >> c)  
            throw InvalidConversionException();
    }
    if (type == CHAR)
        value = static_cast<double>(literal[0]);
    toChar(value, literal);
    toInt(value, literal);
    toFloat(value, type, literal);
    toDouble(value, type, literal);
}

ScalarConverter::~ScalarConverter() {}
