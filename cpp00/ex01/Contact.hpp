#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

class Contact {

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string secret;

public:
	void		setInfo();
	void		displaySavedContact();
	void		displaySearchContact();
};

std::string	getInput(std::string prompt);

#endif
