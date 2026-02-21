#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;

        // Ask intern to create a form
        AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");

        if (!form)
            return 1;

        Bureaucrat boss("Boss", 1);

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form; // VERY important
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}