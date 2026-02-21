#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern intern;
        AForm* form[4];
        // Ask intern to create a form
        form[0] = intern.makeForm("robotomy request", "Bender");
        form[1] = intern.makeForm("shrubbery creation", "Home");
        form[2] = intern.makeForm("presidential pardon", "Criminal");
        form[3] = intern.makeForm("non existing", "lorem");
        std::cout << std::endl;

        Bureaucrat boss("Boss", 1);

        for (int i = 0; i < 4; i++)
        {
            if (form[i])
            {
                boss.signForm(*form[i]);
                boss.executeForm(*form[i]);
                std::cout << std::endl;
            }
        }

        for (int i = 0; i < 4; i++)
            delete form[i];
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
