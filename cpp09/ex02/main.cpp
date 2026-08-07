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

void debugVec(const char* name, std::vector<int>& v)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}


int main(int ac, char** av)
{
	try
	{
		if (ac <= 2)
			throw std::invalid_argument("Usage: ./PmergeMe 4 6 3 2 5 ...");
		
		PmergeMe P;
		P.parseArgs(ac, av);
		debugVec("Before:\t", P.getVect());
		P.sortVect();
		// P.sortDeque();
		debugVec("After:\t", P.getVect());

		std::cout << std::endl;
		std::cout << "Comparisons: "
          << PmergeMe::nbr_of_comps / 2
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