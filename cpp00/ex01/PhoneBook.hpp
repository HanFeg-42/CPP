#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		
	public:
		int		index;
		// PhoneBook();
		void add_contact();
		void search_contact();
		void exit_app();

};

#endif
