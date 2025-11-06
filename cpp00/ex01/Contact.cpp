#include "Contact.hpp"

std::string Contact::get_first_name()
{
    return (first_name);
}

std::string Contact::get_last_name()
{
    return (last_name);
}

std::string Contact::get_nickname()
{
    return (nickname);
}

std::string Contact::get_phone_num()
{
    return (phone_num);
}

std::string Contact::get_secret()
{
    return (secret);
}

void		Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void		Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void		Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void		Contact::set_phone_num(std::string phone_num)
{
    this->phone_num = phone_num;
}

void		Contact::set_secret(std::string secret)
{
    this->secret = secret;
}


void    Contact::set_info()
{
    std::cout << "Enter the First Name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter the Last Name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter the nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phone_num);
    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, secret);
}
