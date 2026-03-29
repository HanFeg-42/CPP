#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    try
    {   
        if (ac != 2)
            throw ScalarConverter::InvalidArgException();
        ScalarConverter::convert(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}