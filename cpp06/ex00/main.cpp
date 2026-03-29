#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

int main(int ac, char *av[])
{
	try
	{   
		if (ac != 2)
			throw ScalarConverter::InvalidArgException();
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	double max_double_value = std::numeric_limits<double>::max();

	std::cout << "The maximum value of a double is: " 
			  << std::setprecision(1) // Use setprecision to display more digits
			  << max_double_value << std::endl;
	return 0;
}