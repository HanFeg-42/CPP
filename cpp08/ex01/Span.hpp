#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span {
    std::vector<int> v;
    unsigned int N;
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    template <typename Iter>
    void addRange(Iter start, Iter end)
    {
        if (v.size() + std::distance(start, end) > N)
            throw MaximunReachedException();
        v.insert(v.end(), start, end);
    }

    class MaximunReachedException : public std::exception {
        public:
            const char* what() const throw();
    };
};
