// #include "PmergeMe.hpp"
// #include <sstream>
// #include <algorithm>
// #include <utility>
// #include <deque>
// #include <vector>

// int PmergeMe::nbr_of_comps = 0;

// PmergeMe::PmergeMe(/* args */)
// {
// }

// PmergeMe::~PmergeMe()
// {
// }

// template <typename Container>
// void debugVec(const char* name, const Container& v)
// {
//     std::cout << name << ": ";
//     for (size_t i = 0; i < v.size(); ++i)
//         std::cout << v[i] << " ";
//     std::cout << "\n";
// }

// void PmergeMe::parseArgs(int ac, char** av)
// {
// 	for (int i = 1; i < ac; i++)
// 	{
//         std::stringstream ss(av[i]);
//         int n;
//         char c;
//         ss >> n;
//         if (ss.fail() || ss >> c || n < 0)
//             throw std::runtime_error("Error");
//         std::vector<int>::const_iterator it = std::find(vect.begin(), vect.end(), n);
//         if (it != vect.end())
//             throw std::runtime_error("Error");

//         vect.push_back(n);
//         deq.push_back(n);
// 	}
// }

// void PmergeMe::printVect()
// {
//     for (size_t i = 0; i < vect.size(); i++)
//         std::cout << vect[i] << " ";
// }

// bool _comp(int &a, int &b)
// {
//     PmergeMe::nbr_of_comps++;
//     return a < b;
// }

// template <typename Container>
// void swapPair(Container& seq, int idx, int lvl)
// {
//     if (lvl == 1)
//         std::swap(seq[idx - 1], seq[idx]);
//     else
//     {
//         typename Container::iterator first = seq.begin() + idx - lvl;
//         typename Container::iterator last = seq.begin() + idx;
//         std::swap_ranges(first, last, last);
//     }
// }

// template <typename Container>
// void sortPairs(Container& seq, int lvl)
// {
//     for (size_t i = lvl - 1; i + lvl < seq.size(); i += (lvl * 2))
//     {
//         if (_comp(seq[i + lvl], seq[i]))
//             swapPair(seq, i + 1, lvl);
//     }
// }

// template <typename Container>
// void initPendAndMain(Container& pend,
//                     Container& main,
//                     Container& seq,
//                     size_t lvl,
//                     std::vector<int>& labels)
// {
//     // ta7ta 3onwan l "HARDCODE"
//     size_t i = 0;
//     while (i < seq.size())
//     {
//         if (seq.size() - main.size() - pend.size() < (size_t)lvl) // kml
//             break;
//         while (i < lvl * 2 && i < seq.size())
//         {
//             main.push_back(seq[i]);
//             i++;
//         }
//         if (seq.size() - main.size() - pend.size() < lvl) // kml
//             break;
//         size_t stop = i + lvl;
//         while (i < stop && i < seq.size())
//         {
//             pend.push_back(seq[i]);
//             i++;
//         }
//         if (seq.size() - main.size() - pend.size() < lvl) // kml
//             break;
//         stop = i + lvl;
//         while (i < stop && i < seq.size())
//         {
//             main.push_back(seq[i]);
//             i++;
//         }
//         labels.push_back(main.size() / lvl - 1);
//     }
//     // debugVec("seq after sortPairs", seq);
//     // debugVec("main", main);
//     // debugVec("pend", pend);
// }

// template <typename Container>
// void updateSeq(Container& seq, Container main)
// {
//     std::copy(main.begin(), main.end(), seq.begin());
// }

// template <typename Container>
// bool elementLess(const Container& main, int elemIdxMain,
//                  const Container& pend, int elemIdxPend, int lvl)
// {
//     int a = main[(elemIdxMain + 1) * lvl - 1]; // last value of main elem
//     int b = pend[(elemIdxPend + 1) * lvl - 1]; // last value of pend elem
//     return _comp(a, b);
// }

// template <typename Container>
// void insertElement(Container& main,
//                    const Container& pend, int elemIdxPend,
//                    int posElem, int lvl,
//                    std::vector<int>& labels)
// {
//     Container block;
//     int start = elemIdxPend * lvl;
//     for (int i = 0; i < lvl; ++i)
//         block.push_back(pend[start + i]);

//     main.insert(main.begin() + posElem * lvl, block.begin(), block.end());
//     for (size_t i = posElem; i < labels.size(); i++)
//         labels[i]++;
// }

// template <typename Container>
// int findInsertPos(const Container& main,
//                   const Container& pend,
//                   size_t elemIdxPend, int lvl,
//                   std::vector<int>& labels)
// {
//     //binary search
//     int left = 0;
//     int right = (labels.empty() || elemIdxPend >= labels.size())
//                 ? main.size() / lvl
//                 : labels[elemIdxPend]; // number of elements

//     while (left < right) {
//         int mid = (left + right) / 2;
//         if (elementLess(main, mid, pend, elemIdxPend, lvl)) {
//             left = mid + 1;
//         } else {
//             right = mid;
//         }
//     }
//     return left;
// }

// // container-independent: pure index arithmetic, no need to templatize
// int jacobsthalN(int n) {
//     // n >= 1, J(1) = 1, J(2) = 3, J(3) = 5, ...
//     // simple iterative version:
//     if (n == 1) return 1;
//     if (n == 2) return 3;
//     int j1 = 1, j2 = 3;
//     for (int i = 3; i <= n; ++i) {
//         int j = j2 + 2 * j1;
//         j1 = j2;
//         j2 = j;
//     }
//     return j2;
// }

// // container-independent: builds an index order, no container involved
// std::vector<int> buildInsertionOrder(size_t pend_elmt) {
//     std::vector<int> order;
//     if (pend_elmt == 0) return order;

//     int prev = 1; // b1 anchor

//     for (int n = 2;; ++n) {
//         int j = jacobsthalN(n); // 3, 5, 11, ...
//         if (j > (int)pend_elmt + 1)
//             break;

//         for (int bIndex = j; bIndex > prev; --bIndex) {
//             int pendIdx = bIndex - 2; // l idx f pend kaybdaw mn 0 wlakin betas kaybdaw n 2 f pend
//             if (pendIdx >= 0 && pendIdx < (int)pend_elmt)
//                 order.push_back(pendIdx);
//         }
//         prev = j;
//         if (prev >= (int)pend_elmt + 1) // ila kan beta f pend only
//             break;
//     }

//     std::vector<bool> used(pend_elmt, false);
//     for (size_t i = 0; i < order.size(); ++i)
//         used[order[i]] = true;

//     for (int idx = (int)pend_elmt - 1; idx >= 0; --idx) {
//         if (!used[idx])
//             order.push_back(idx);
//     }
//     return order;
// }

// template <typename Container>
// void insertPendIntoMain(Container& pend,
//                         Container& main,
//                         int lvl,
//                         std::vector<int>& labels)
// {
//     size_t pend_elmt = pend.size() / lvl;
//     if (pend_elmt == 0)
//         return;

//     std::vector<int> order = buildInsertionOrder(pend_elmt);

//     for (size_t k = 0; k < order.size(); ++k) {
//         int pendIdx = order[k]; // element index in pend

//         int posElem = findInsertPos(main, pend, pendIdx, lvl, labels);

//         insertElement(main, pend, pendIdx, posElem, lvl, labels);
//     }
// }

// template <typename Container>
// void fordJohnson(Container& seq, size_t lvl)
// {
//     // std::cout << "\n-------recursion lvl = " << lvl << "-----\n";
//     sortPairs(seq, lvl);
//     // debugVec("seq in lvl", seq);
//     if (lvl * 2 <= seq.size() / 2)
//         fordJohnson(seq, lvl * 2);
//     // std::cout << "\n--back recursion lvl = " << lvl << "-----\n";

//     Container pend;
//     Container main;
//     std::vector<int> labels;
//     initPendAndMain(pend, main, seq, lvl, labels);
//     if (pend.empty())
//         return updateSeq(seq, main);
//     insertPendIntoMain(pend, main, lvl, labels);
//     updateSeq(seq, main);
// }

// void PmergeMe::sortVect()
// {
//     fordJohnson(vect, (size_t)1);
//     std::cout << "\nAfter (vector):\t";
//     printVect();
// }

// void PmergeMe::sortDeque()
// {
//     fordJohnson(deq, (size_t)1);
//     std::cout << "\nAfter (deque):\t";
//     printDeque();
// }

// void PmergeMe::printDeque()
// {
//     for (size_t i = 0; i < deq.size(); i++)
//         std::cout << deq[i] << " ";
// }