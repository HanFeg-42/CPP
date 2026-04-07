#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(3, 6);

    try {
        // found value
        easyfind(v, 6);
        std::cout << std::endl;
        // non found value
        easyfind(v, 8);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
