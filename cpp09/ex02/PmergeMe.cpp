#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <utility>

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}


void PmergeMe::parseArgs(int ac, char** av)
{
	for (int i = 1; i < ac; i++)
	{
        std::stringstream ss(av[i]);
        int n;
        char c;
        ss >> n;
        if (ss.fail() || ss >> c || n < 0)
            throw std::runtime_error("Error");
        std::vector<int>::const_iterator it = std::find(vect.begin(), vect.end(), n);
        if (it != vect.end())
            throw std::runtime_error("Error");

        vect.push_back(n);
	}
}

void PmergeMe::printVect()
{
    for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
}

bool _comp(int &a, int &b)
{
    PmergeMe::nbr_of_comps++;
    return a < b;
}

void swapPair(std::vector<int>& seq, int idx, int lvl)
{
    if (lvl == 1)
        std::swap(seq[idx - 1], seq[idx]);
    else
    {
        std::vector<int>::iterator first = seq.begin() +  idx - lvl;
        std::vector<int>::iterator last = seq.begin() +  idx;
        std::swap_ranges(first, last, last);
    }
}

void sortPairs(std::vector<int>& seq, int lvl)
{
    for (int i = lvl - 1; i < seq.size(); i += (lvl * 2))
    {
        if (_comp(seq[i + lvl], seq[i]))
            swapPair(seq, i + 1, lvl);
    }
}

void initPendAndMain(std::vector<int>& pend, std::vector<int>& main, std::vector<int>& seq, int lvl, std::vector<std::pair<int, int>> labels)
{
    // ta7ta 3onwan l "HARDCODE"
    int i = 0;
    while (i < seq.size())
    {        
        if (seq.size() - main.size() - pend.size() < lvl) // kml
            break;
        while (i < lvl * 2 && i < seq.size())
        {
            main.push_back(seq[i]);
            i++;
        }
        if (seq.size() - main.size() - pend.size() < lvl) // kml
            break;
        int stop = i + lvl;
        while (i < stop && i < seq.size())
        {
            pend.push_back(seq[i]);
            i++;
        }
        if (seq.size() - main.size() - pend.size() < lvl) // kml
            break;
        stop = i + lvl;
        while (i < stop && i < seq.size())
        {
            main.push_back(seq[i]);
            i++;
        }
        labels.push_back(std::make_pair(pend.size() / lvl, main.size() / lvl));
    }
}

void updateSeq(std::vector<int>& seq, std::vector<int> main)
{
    std::copy(main.begin(), main.end(), seq.begin());
}

void insertPendIntoMain(std::vector<int>& pend, std::vector<int>& main, int lvl, std::vector<std::pair<int, int>> labels)
{
    int prevJ = 1, currJ = 1, tmpJ = currJ;

    while (!pend.empty())
    {
        size_t pend_elmt = pend.size() / lvl;
        currJ = jacobsthal(prevJ, currJ);
        prevJ = tmpJ;
        tmpJ = currJ;

        if (pend_elmt > currJ - prevJ)
        {
            // insert using jacobsthal
        }
        for (size_t i = 0; i < pend_elmt; i++)
        {
            
        }
        

    }
    
}

void fordJohnson(std::vector<int>& seq, int lvl)
{
    sortPairs(seq, lvl);
    if (lvl * 2 <= seq.size())
        fordJohnson(seq, lvl * 2);
    std::vector<int> pend;
    std::vector<int> main;
    std::vector<std::pair<int, int>> labels;
    initPendAndMain(pend, main, seq, lvl, labels);
    if (pend.empty())
        return updateSeq(seq, main);
    insertPendIntoMain(pend, main, lvl, labels);
    updateSeq(seq, main);
}

void PmergeMe::sortVect()
{
    fordJohnson(vect, 1);
}
