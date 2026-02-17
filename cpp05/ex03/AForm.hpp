#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string const	_name;
	int const			_signGrade;
	int const			_execGrade;
	bool				_isSigned;
public:
	AForm();
	AForm(std::string const name, int signGrade, int execGrade);
	AForm(const AForm & other);
	AForm & operator=(const AForm & other);
	~AForm();

	const std::string&	getName() const;
	bool        getIsSigned() const;
	int         getSignGrade() const;
	int         getExecGrade() const;
	void        beSigned(const Bureaucrat& bureaucrat);
	void		executionCheck(Bureaucrat const & executor) const;
	virtual void		execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormNotExecutedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream& out, const AForm& obj);
