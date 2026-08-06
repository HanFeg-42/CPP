#include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>


int main(int ac, char** av)
{
	try
	{
		if (ac <= 2)
			throw std::invalid_argument("Usage: ./PmergeMe 4 6 3 2 5 ...");
		
		PmergeMe P;
		P.parseArgs(ac, av);
		std::cout << "Before:\t";
		P.printVect();
		P.sortVect();
		// P.sortQueue();


		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}