#include <algorithm>
#include <iostream>
#include <exception>

/**
 * @brief Find the first occurrence of the second parameter in the first parameter
 * 
 * @param t		a conatiner of intergers
 * @param value	the number to be found in the container
 * @throws std::runtime_error if value not found
 */
template<typename T>
void easyfind(T t, int value)
{
	typename T::iterator it = std::find(t.begin(), t.end(), value);
	if (it != t.end())
		std::cout << "The value: " << value << " is found.\n";
	else
		throw std::runtime_error("value not found!");
}
