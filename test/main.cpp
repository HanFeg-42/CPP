#include <iostream>
//#include "test.hpp"
template <typename T>
T add(T a, T b)
{
    std::cout << "template function" << std::endl;
    return (a + b);
}


int add(int a, int b)
{
    std::cout << "normal function" << std::endl;
    return a + b;
}
int main()
{
    std::cout << add(9, 4) << std::endl;
}