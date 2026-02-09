#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Itadori", 2);
		Form f("qqq", 1, 3);
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
