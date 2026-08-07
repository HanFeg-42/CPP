#include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#include <cmath>

int comparisonLimit(int n)
{
    int total = 0;

    for (int k = 1; k <= n; ++k)
    {
        double value = (3.0 * k) / 4.0;
        total += static_cast<int>(
            std::ceil(std::log(value) / std::log(2.0))
        );
    }

    return total;
}

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
		P.sortDeque();

		std::cout << std::endl;
		std::cout << "Comparisons: "
          << PmergeMe::nbr_of_comps
          << " / "
          << comparisonLimit(ac - 1)
          << "\n";
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}