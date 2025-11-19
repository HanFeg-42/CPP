#include "Contact.hpp"

std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickname()
{
    return (nickname);
}

std::string Contact::getPhoneNum()
{
    return (phoneNum);
}

std::string Contact::getSecret()
{
    return (secret);
}

void		Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void		Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void		Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void		Contact::setPhoneNum(std::string phoneNum)
{
    this->phoneNum = phoneNum;
}

void		Contact::setSecret(std::string secret)
{
    this->secret = secret;
}

bool    isValidPhone(std::string phone)
{
    if (phone.empty())
        return false;
    for (size_t i = 0; i < phone.length(); i++)
    {
        if (!std::isdigit(phone[i]) && phone[i] != ' ' && phone[i] != '+' && phone[i] != '-')
            return false;
    }
    return true;
}

void    Contact::setInfo()
{
    while (firstName.empty())
    {
        std::cout << "Enter the First Name: ";
        std::getline(std::cin, firstName);
    }
    while (lastName.empty())
    {
        std::cout << "Enter the Last Name: ";
        std::getline(std::cin, lastName);
    }
    while (nickname.empty())
    {
        std::cout << "Enter the nickname: ";
        std::getline(std::cin, nickname);
    }
    while (!isValidPhone(phoneNum))
    {
        std::cout << "Enter the phone number: ";
        std::getline(std::cin, phoneNum);
    }
    while (secret.empty())
    {
        std::cout << "Enter the darkest secret: ";
        std::getline(std::cin, secret);
    }
}
