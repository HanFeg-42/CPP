#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> v(4, 6); // 4 elements all equal to 6
    std::list<int> l(4, 3);
    std::deque<int> d(4, 8);

    try {
        // found value
        
        std::cout << "Vector:\n";
        easyfind(v, 6);
        std::cout << std::endl;

        std::cout << "List:\n";
        easyfind(l, 3);
        std::cout << std::endl;

        std::cout << "Deque:\n";
        easyfind(d, 8);
        std::cout << std::endl;     
        
        // non found value
        easyfind(v, 8);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
