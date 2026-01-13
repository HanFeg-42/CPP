#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other.name)
{
    if (other.grade < 1)
        throw GradeTooHighException();
    else if (other.grade > 150)
        throw GradeTooLowException();
    _grade = other.grade;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != other)
        _grade = other.grade;
    return *this;
}

std::string const Bureaucrat::getName() const
{
    return _name;
}

int     Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

Bureaucrat::~Bureaucrat()
{
}
