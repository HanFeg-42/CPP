#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signGrade(150), _execGrade(150), _isSigned(false)
{
}

Form::Form(std::string const name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form & other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
}

Form & Form::operator=(const Form & other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string& Form::getName() const
{
	return _name;
}

const bool	Form::getIsSigned() const
{
	return _isSigned;
}

const int	Form::getSignGrade() const
{
	return _signGrade;
}

const int	Form::getExecGrade() const
{
	return _execGrade;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form \"" << obj.getName() << "\""
        << ", sign grade: " << obj.getSignGrade()
        << ", exec grade: " << obj.getExecGrade()
        << ", status: " << (obj.getIsSigned() ? "signed" : "not signed");

    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade too HIGH!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade too LOW!";
}

Form::~Form()
{
}
