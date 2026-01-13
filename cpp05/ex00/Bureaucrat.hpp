#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(const Bureaucrat & other);
    Bureaucrat & operator=(const Bureaucrat & other);
    ~Bureaucrat();

    std::string const getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException() {}
        const char* what() const throw() { return "Error: Grade too HIGH!"; }
    };
    class GradeTooLowException : public std::exception {
   public:
        GradeTooHighException() {}
        const char* what() const throw() { return "Error: Grade too LOW!"; }
    };
};

