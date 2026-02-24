#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(time(0));

	try
	{
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("rob");
		PresidentialPardonForm pardon("Sukuna");

		std::cout << boss << std::endl;

		boss.signForm(shrub);
		boss.executeForm(shrub);

		boss.signForm(robot);
		boss.executeForm(robot);

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
