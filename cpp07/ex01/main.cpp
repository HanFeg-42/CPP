#include <iostream>
#include "iter.hpp"
#include <iostream>
#include <string>

void increment(int& value)
{
    value++;
}

void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main()
{
	std::cout << "-------INT TEST-------\n";
	int arr[4] = {1, 3, 4, 6};

	::iter(arr, 4, print);
	std::cout << std::endl;

	::iter(arr, 4, increment);
	::iter(arr, 4, print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------CONST INT TEST-------\n";
	const int carr[4] = {2, 6, 9, 0};

	::iter(carr, 4, print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------STRING TEST-------\n";
	std::string str[3] = {"Buttercup", "Blossom", "Bubbles"};

	::iter(str, 3, print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------CHAR TEST-------\n";
	char c[4] = {'a', 'b', 'c', 'd'};

	::iter(c, 4, toUpper);
	::iter(c, 4, print);
	std::cout << std::endl;
    return 0;
}