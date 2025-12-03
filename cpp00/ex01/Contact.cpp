#include "Contact.hpp"

bool    isValidPhone(std::string phone)
{
	if (phone.empty())
		return false;
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!std::isdigit(phone[i]) && phone[i] != ' ' && phone[i] != '+')
			return false;
	}
	return true;
}

void	throw_error(std::string err)
{
	std::cout << err << std::endl;
	exit(EXIT_FAILURE);
}

void    Contact::setInfo()
{
	do {
		std::cout << "Enter the First Name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof() || std::cin.fail())
			throw_error("Error: EOF");
	} while (firstName.empty());
	do {
		std::cout << "Enter the Last Name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof() || std::cin.fail())
			throw_error("Error: EOF");
	}while (lastName.empty());
	do {
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof() || std::cin.fail())
			throw_error("Error: EOF");
	} while (nickname.empty());
	do {
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, phoneNum);
		if (std::cin.eof() || std::cin.fail())
			throw_error("Error: EOF");
	} while (!isValidPhone(phoneNum));
	do {
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof() || std::cin.fail())
			throw_error("Error: EOF");
	} while (secret.empty());
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
