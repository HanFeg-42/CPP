#pragma once

#include <iostream>

class Form
{
private:
	std::string const _name;
	bool _is_signed;
	int const _sign_grade;
	int const _exec_grade;
public:
	Form();
	Form(std::string const name, int grade);
	Form(const Form & other);
	Form & operator=(const Form & other);
	~Form();

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

