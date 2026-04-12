#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // MutantStack();
    // MutantStack(const MutantStack& other);
    // MutantStack& operator=(const MutantStack& other);
    // ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};

#include "MutantStack.tpp"
