#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char** av)
{
	try
	{
		if (ac <= 2)
			throw std::invalid_argument("Usage: ./PmergeMe 4 6 3 2 5 ...");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}