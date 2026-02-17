#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	int const			_signGrade;
	int const			_execGrade;
	bool				_isSigned;
public:
	Form();
	Form(std::string const name, int signGrade, int execGrade);
	Form(const Form & other);
	Form & operator=(const Form & other);
	~Form();

	const std::string& getName() const;
	const bool        getIsSigned() const;
	const int         getSignGrade() const;
	const int         getExecGrade() const;
	void        beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream& out, const Form& obj);
