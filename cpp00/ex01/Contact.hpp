#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact {

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_num;
		std::string secret;

	public:
		void		set_info();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_num();
		std::string get_secret();
		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nickname(std::string nickname);
		void		set_phone_num(std::string phone_num);
		void		set_secret(std::string secret);
};

#endif
