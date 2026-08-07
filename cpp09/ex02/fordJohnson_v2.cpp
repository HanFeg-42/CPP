// #include "PmergeMe.hpp"
// #include <sstream>
// #include <algorithm>
// #include <utility>

// int PmergeMe::nbr_of_comps = 0;

// PmergeMe::PmergeMe(/* args */)
// {
// }

// PmergeMe::~PmergeMe()
// {
// }
// void debugVec(const char* name, const std::vector<int>& v) {
//     std::cout << name << ": ";
//     for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
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

// void swapPair(std::vector<int>& seq, int idx, int lvl)
// {
//     if (lvl == 1)
//         std::swap(seq[idx - 1], seq[idx]);
//     else
//     {
//         std::vector<int>::iterator first = seq.begin() +  idx - lvl;
//         std::vector<int>::iterator last = seq.begin() +  idx;
//         std::swap_ranges(first, last, last);
//     }
// }

// void sortPairs(std::vector<int>& seq, int lvl)
// {
//     for (size_t i = lvl - 1; i + lvl < seq.size(); i += (lvl * 2))
//     {
//         if (_comp(seq[i + lvl], seq[i]))
//             swapPair(seq, i + 1, lvl);
//     }
// }

// void initPendAndMain(std::vector<int>& pend,
//                      std::vector<int>& main,
//                      std::vector<int>& seq,
//                      size_t lvl,
//                      std::vector<std::pair<int, int> >& labels)
// {
//     pend.clear();
//     main.clear();
//     labels.clear();

//     size_t numElems = seq.size() / lvl;

//     // element indices where pairs reside: e = 0,2,4,... for b_k; e+1 for a_k
//     int mainElemCount = 0;
//     int pendElemCount = 0;

//     // 1) Build main: element for b1, a1, a2, a3, ...
//     // 2) Build pend: b2, b3, ... (+ odd element)
//     // We do this by walking the elements.

//     // First pair: (b1,a1)
//     if (numElems >= 1) {
//         // b1 -> main
//         for (size_t i = 0; i < lvl; ++i)
//             main.push_back(seq[i]); // element 0
//         ++mainElemCount;
//     }
//     if (numElems >= 2) {
//         // a1 -> main
//         for (size_t i = lvl; i < 2*lvl; ++i)
//             main.push_back(seq[i]); // element 1
//         ++mainElemCount;
//     }

//     // Remaining pairs: (b2,a2), (b3,a3), ...
//     for (size_t pairIdx = 2; pairIdx*2 <= numElems; ++pairIdx) {
//         size_t bElem = 2*pairIdx - 2;
//         size_t aElem = 2*pairIdx - 1;

//         // b_k -> pend
//         size_t startB = bElem * lvl;
//         for (size_t i = 0; i < lvl; ++i)
//             pend.push_back(seq[startB + i]);
//         int pendIndex = pendElemCount;
//         ++pendElemCount;

//         // a_k -> main
//         size_t startA = aElem * lvl;
//         for (size_t i = 0; i < lvl; ++i)
//             main.push_back(seq[startA + i]);
//         int mainIndex = mainElemCount;
//         ++mainElemCount;

//         // label: pend element 'pendIndex' is bounded by main element 'mainIndex'
//         labels.push_back(std::make_pair(pendIndex, mainIndex));
//     }

//     // Odd element (if any element that does not form a full pair at this level)
//     if (seq.size() % lvl != 0 || numElems * lvl < seq.size()) {
//         // crude: treat trailing ints as one odd element and push to pend
//         size_t startOdd = numElems * lvl;
//         if (startOdd < seq.size()) {
//             for (size_t i = startOdd; i < seq.size(); ++i)
//                 pend.push_back(seq[i]);
//             int pendIndex = pendElemCount;
//             ++pendElemCount;
//             // odd element has no partner, mark bound as -1
//             labels.push_back(std::make_pair(pendIndex, -1));
//         }
//     }
// }
// void updateSeq(std::vector<int>& seq, std::vector<int> main)
// {
//     std::copy(main.begin(), main.end(), seq.begin());
// }

// // Compare elements by their last value.
// bool elementLess(const std::vector<int>& main, int elemIdxMain,
//                  const std::vector<int>& pend, int elemIdxPend, int lvl)
// {
//     int a = main[(elemIdxMain + 1) * lvl - 1]; // last value of main elem
//     int b = pend[(elemIdxPend + 1) * lvl - 1]; // last value of pend elem
//     return _comp(a, b); // your comparison counter
// }

// // Insert the pend element (block of size lvl) into main at element position posElem
// void insertElement(std::vector<int>& main,
//                    const std::vector<int>& pend, int elemIdxPend,
//                    int posElem, int lvl)
// {
//     std::vector<int> block;
//     block.reserve(lvl);
//     int start = elemIdxPend * lvl;
//     for (int i = 0; i < lvl; ++i)
//         block.push_back(pend[start + i]);

//     // Insert block of ints at position posElem * lvl in main.
//     main.insert(main.begin() + posElem * lvl, block.begin(), block.end());
// }

// int findInsertPos(const std::vector<int>& main,
//                   const std::vector<int>& pend,
//                   int elemIdxPend, int lvl)
// {
//     int left = 0;
//     int right = main.size() / lvl; // number of elements

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

// std::vector<int> buildInsertionOrder(size_t pend_elmt) {
//     std::vector<int> order;
//     if (pend_elmt == 0) return order;

//     int prev = 1; // b1 anchor
//     // generate Jacobsthal values up to pend_elmt+1
//     for (int n = 2;; ++n) {
//         int j = jacobsthalN(n); // 3, 5, 11, ...
//         if (j > (int)pend_elmt + 1)
//             break;

//         int hi = j;
//         if (hi <= prev)
//             continue;

//         // push elements corresponding to b_hi .. b_{prev+1} in reverse order
//         // b2 -> pend[0], so pendIdx = bIndex - 2
//         for (int bIndex = hi; bIndex > prev; --bIndex) {
//             int pendIdx = bIndex - 2;
//             if (pendIdx >= 0 && pendIdx < (int)pend_elmt)
//                 order.push_back(pendIdx);
//         }
//         prev = hi;
//         if (prev >= (int)pend_elmt + 1)
//             break;
//     }

//     // Mark used indices
//     std::vector<bool> used(pend_elmt, false);
//     for (size_t i = 0; i < order.size(); ++i)
//         used[order[i]] = true;

//     // Remaining elements in reverse order, starting from last (b_m, ..., b2)
//     for (int idx = (int)pend_elmt - 1; idx >= 0; --idx) {
//         if (!used[idx])
//             order.push_back(idx);
//     }
//     return order;
// }

// int findInsertPosBounded(const std::vector<int>& main,
//                          const std::vector<int>& pend,
//                          int elemIdxPend, int lvl,
//                          int boundElem) // index of a_k in main, or -1 for full range
// {
//     int left = 0;
//     int right = (boundElem == -1)
//         ? (int)(main.size() / lvl)
//         : boundElem; // search up to a_k only[web:2][web:4]

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

// void insertPendIntoMain(std::vector<int>& pend,
//                         std::vector<int>& main,
//                         int lvl,
//                         std::vector<std::pair<int, int> >& labels)
// {
//     size_t pend_elmt = pend.size() / lvl;
//     if (pend_elmt == 0)
//         return;

//     std::vector<int> order = buildInsertionOrder(pend_elmt);

//     for (size_t k = 0; k < order.size(); ++k) {
//         int pendIdx = order[k]; // pend element index (0..pend_elmt-1)

//         // find label for this pendIdx
//         int boundElem = -1;
//         for (size_t i = 0; i < labels.size(); ++i) {
//             if (labels[i].first == pendIdx) {
//                 boundElem = labels[i].second;
//                 break;
//             }
//         }

//         int posElem = findInsertPosBounded(main, pend, pendIdx, lvl, boundElem);
//         insertElement(main, pend, pendIdx, posElem, lvl);
//     }
// }
// void fordJohnson(std::vector<int>& seq, size_t lvl)
// {
//     std::cout << "\n-------recursion lvl = " << lvl << "-----\n";
//     sortPairs(seq, lvl);
//     debugVec("seq in lvl", seq);
//     if (lvl * 2 <= seq.size() / 2)
//         fordJohnson(seq, lvl * 2);
//     std::cout << "\n--back recursion lvl = " << lvl << "-----\n";

//     std::vector<int> pend;
//     std::vector<int> main;
//     std::vector<std::pair<int, int> > labels;
//     initPendAndMain(pend, main, seq, lvl, labels);
//     if (pend.empty())
//         return updateSeq(seq, main);
//     insertPendIntoMain(pend, main, lvl, labels);
//     updateSeq(seq, main);
// }

// void PmergeMe::sortVect()
// {
//     fordJohnson(vect, 1);
//     std::cout << "\nAfter:\t";
//     printVect();
// }
