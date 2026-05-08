#include "RPN.hpp"

int main(int ac, char** av)
{
    try
    {
        if (ac != 2)
            throw std::invalid_argument("Usage: ./RPN <expression>");

        RPN obj;
        std::cout << obj.evaluate(av[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}