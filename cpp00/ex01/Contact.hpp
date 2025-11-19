#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNum;
		std::string secret;

	public:
		void		setInfo();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNum();
		std::string getSecret();
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickname);
		void		setPhoneNum(std::string phoneNum);
		void		setSecret(std::string secret);
};

bool    isValidPhone(std::string phone);

#endif
