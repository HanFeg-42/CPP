#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm *shrubCreation(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}
AForm *robotomyRqst(std::string const target)
{
	return (new RobotomyRequestForm(target));
}
AForm *presidentialPardon(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string const name, std::string const target) const
{
	std::string formType[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*forms[3])(std::string) = {&shrubCreation, &robotomyRqst, &presidentialPardon};

	for (int i = 0; i < 3; i++)
		if (formType[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i](target);
		}
	std::cerr << "Intern can't create " << name << "\n";
	return NULL;
}

Intern::~Intern()
{
}
