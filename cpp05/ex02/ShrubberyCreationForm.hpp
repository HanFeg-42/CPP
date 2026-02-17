#pragma once

#include "AForm.hpp"
#include "fstream"
#include "string"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const name);
	ShrubberyCreationForm(const ShrubberyCreationForm & other);
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
	~ShrubberyCreationForm();

	void		execute(Bureaucrat const & executor) const;

	class FileOpenException : public std::exception {
	public:
		const char* what() const throw();
	};
};
