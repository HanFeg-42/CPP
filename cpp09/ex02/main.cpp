#include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <ctime>

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

void printComps(int n)
{
	std::cout << std::endl;
	std::cout << "Comparisons: "
		<< PmergeMe::nbr_of_comps / 2
		<< " / "
		<< comparisonLimit(n)
		<< "\n";
}

void debugVec(const char* name, std::vector<int>& v)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

void printExecTime(std::string c, double time, int n)
{
	std::cout << "Time to process a range of " << n << " elements with std::" << c << " : "
			  << (static_cast<double>(time) / CLOCKS_PER_SEC) * 1000000.0
			  << " us"
			  << std::endl;
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

		std::clock_t startV = std::clock();
		P.sortVect();
		std::clock_t endV = std::clock();

		std::clock_t startD = std::clock();
		P.sortDeque();
		std::clock_t endD = std::clock();

		debugVec("After:\t", P.getVect());

		printExecTime("vector", endV - startV, ac - 1);
		printExecTime("deque", endD - startD, ac - 1);

		// printComps(ac - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}