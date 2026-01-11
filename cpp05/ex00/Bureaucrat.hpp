#pragma once

#include <iostream>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat & other);
    Bureaucrat & operator=(const Bureaucrat & other);
    ~Bureaucrat();

    std::string const getName() const;
    int     getGrade() const;
    void    incrementGrade() const;
    void    decrementGrade() const;
};

