#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook {
	private:
		Contact	contacts[8];
		int		index;
		int		total;

	public:
		PhoneBook();

		void	start();
		void	addContact();
		void	searchContact();
};

#endif
