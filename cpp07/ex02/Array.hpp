#pragma once

template<class T>
class Array
{
private:
    T* data;
    unsigned int size;
public:
    Array() : size(0), data(NULL) {}
    Array(unsigned int n) : size(n) {
        data = new T[size];
    }
    ~Array() { delete[] data; }
};
