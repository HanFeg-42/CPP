#pragma once

#include <iostream>
#include <exception>

template<class T>
class Array
{
private:
    T* data;
    unsigned int _size;
public:
    Array() : _size(0), data(NULL) {}
    Array(unsigned int n) : _size(n) {
        data = new T[_size];
    }
    Array(const Array& other) : _size(other._size) {
        data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            data[i] = other.data[i];
    }
    Array & operator=(const Array& other) {
        if (this != &other)
        {
            // kayna chii haaja hna what if the allocation failed
            _size = other._size;
            if (data)
                delete[] data;
            data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    ~Array() { delete[] data; }

    class NonAccessibleException : public std::exception {
        public:
            const char* what() const throw() {
                return "Non Accessible!";
            }
    };

    T& operator[](unsigned int i) {
        if (i >= _size)
            throw NonAccessibleException();
        return data[i];
    }
    \
    const T& operator[](unsigned int i) const {
        if (i >= _size)
            throw NonAccessibleException();
        return data[i];
    }

    unsigned int size() const {
        return _size;
    }
};
