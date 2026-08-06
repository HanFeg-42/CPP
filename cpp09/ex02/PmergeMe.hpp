#pragma once

#include <ostream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

class PmergeMe
{
private:
	std::vector<int> vect;

public:
	PmergeMe(/* args */);
	~PmergeMe();

	static int nbr_of_comps;
	
	void parseArgs(int ac, char** av);
	void printVect();
	void sortVect();
};

// constraints
// - only positive integers
// - must use merge-insert sort algo / Ford-Johnson algo
// - 2 diff containers
// - handle +3000 diff integers
// - avoid generic functions
// - follow the output format

// The purpose of this algo is to sort the sequence
// in the minimum number of absolute comparisons.

