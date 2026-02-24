#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("target", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    executionCheck(executor);
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
