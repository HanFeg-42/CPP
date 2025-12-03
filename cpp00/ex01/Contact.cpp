#include "Contact.hpp"


void	throw_error(std::string err)
{
	std::cout << err << std::endl;
	exit(EXIT_FAILURE);
}

std::string	getInput(std::string prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
			throw_error("\nError: EOF");
	} while (input.empty());
	return input;
}

void    Contact::setInfo()
{
	firstName = getInput("Enter the First Name: ");
	lastName = getInput("Enter the Last Name: ");
	nickname = getInput("Enter the nickname: ");
	phoneNum = getInput("Enter the phone number: ");
	secret = getInput("Enter the darkest secret: ");
}

void    print_info(std::string str)
{
    if (str.length() >= 10)
        std::cout << str.substr(0, 9) + "." << "|";
    else
        std::cout << std::setw(10) << str << "|";
}


void    Contact::displaySearchContact()
{
    std::cout << "First Name:\t\t" << firstName << std::endl;
    std::cout << "Lasr Name:\t\t" << lastName << std::endl;
    std::cout << "Nickname:\t\t" << nickname << std::endl;
    std::cout << "Phone number:\t\t" << phoneNum << std::endl;
    std::cout << "Darkest secret:\t\t" << secret << std::endl;
}

void    Contact::displaySavedContact()
{
    print_info(firstName);
    print_info(lastName);
    print_info(nickname);
}
