#include "Bureaucrat.hpp"

int main()
{
	// valid
	try {
		Bureaucrat valid("Hmed", 5);
		std::cout << valid;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	// invalid
	try {
		Bureaucrat invalid("Hmed", 151);
		std::cout << invalid;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	// increment
	try {
		Bureaucrat incre("itachi", 1);
		std::cout << "Before incrementing: " << incre;
		incre.incrementGrade();
		std::cout << "After incrementing: will never print" << incre;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	// decre
	try {
		Bureaucrat decr("madara", 150);
		std::cout << "Before decrementing: " << decr;
		decr.decrementGrade();
		std::cout << "After decrementing: will never print" << decr;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
