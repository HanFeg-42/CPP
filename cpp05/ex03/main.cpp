#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

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
