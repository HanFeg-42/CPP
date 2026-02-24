#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(const RobotomyRequestForm & other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm & other);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;
};
