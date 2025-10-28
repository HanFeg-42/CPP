#include <iostream>
#include "Contact.hpp"

void    Contact::set_info()
{
    std::cout << "Enter the First Name: ";
    std::cin >> Contact::first_name;
    std::cout << "Enter the Last Name: ";
    std::cin >> Contact::last_name;
    std::cout << "Enter the nickname: ";
    std::cin >> Contact::nickname;
    std::cout << "Enter the phone number: ";
    std::cin >> Contact::phone_num;
    std::cout << "Enter the darkest secret: ";
    std::cin >> Contact::secret;
}
