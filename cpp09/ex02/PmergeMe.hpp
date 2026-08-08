#pragma once

#include <ostream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> vect;
	std::deque<int> deq; 

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	static int nbr_of_comps;
	
	void parseArgs(int ac, char** av);
	void sortVect();
	void sortDeque();
	std::vector<int>&  getVect();
	std::deque<int>&  getDeque();
};
