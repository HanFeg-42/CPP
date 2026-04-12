#include "Array.hpp"
#include <iostream>

template<typename T>
void printArr(T arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "\t";
}

int main()
{
    // int * a = new int();
    // std::cout << *a << "\n";

    try
    {
        std::cout << "-----INT ARRAY-----\n";
        Array<int> intArr(5);

        for (unsigned int i = 0; i < intArr.size(); i++)
            intArr[i] = i + 1;
        printArr(intArr, intArr.size());
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "-----STRING ARRAY-----\n";
        Array<std::string> strArr(3);

        strArr[0] = "Blossom";
        strArr[1] = "Bubbles";
        strArr[2] = "Buttercup";

        Array<std::string> cstrArr(strArr);

        printArr(cstrArr, cstrArr.size());
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "---Non accessible data---\n";
        std::cout << strArr[10];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}