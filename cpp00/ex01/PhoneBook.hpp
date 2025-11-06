#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		index = 0;

	public:
		// PhoneBook();
		// int		get_index();
		// void	set_index(int index);
		void	add_contact();
		void	search_contact();
		void	exit_app();

};

#endif
