#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _signGrade(150), _execGrade(150), _isSigned(false)
{
}

AForm::AForm(std::string const name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm & AForm::operator=(const AForm & other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.getName();
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: Grade too HIGH!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: Grade too LOW!";
}


AForm::~AForm()
{
}
