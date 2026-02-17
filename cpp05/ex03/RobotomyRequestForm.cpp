#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("target", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	(void)other;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executionCheck(executor);
	std::cout << "-Drilling noises-\n";
	std::srand(time(0));
	if (std::rand() % 2)
		std::cout << getName() << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed on " << getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
