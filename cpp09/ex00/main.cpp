#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: could not open file.");
        BitcoinExchange btc;

        btc.loadData();
        btc.processInput(av[1]);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}