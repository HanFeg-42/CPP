#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("target", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	executionCheck(executor);
	std::ofstream file((getName() + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileOpenException();
	file << "           *                        *\n";
	file << "          ***                      ***\n";
	file << "         *****                    *****\n";
	file << "        *******                  *******\n";
	file << "       *********        *       *********\n";
	file << "      ***********      ***     ***********\n";
	file << "           #          *****         #\n";
	file << "           #            #           #\n";
	file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Error : Can't open file!";
}
	
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
