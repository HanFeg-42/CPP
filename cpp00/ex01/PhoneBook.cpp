#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), total(0) {}


void    PhoneBook::addContact()
{
    contacts[index].setInfo();
    index = (index + 1) % 8;
    if (total < 8)
        total++;
}

void    print_info(std::string str)
{
    if (str.length() >= 10)
        std::cout << str.substr(0, 9) + "." << "|";
    else
        std::cout << std::setw(10) << str << "|";
}

void    display_all_contacts(int total, Contact contacts[8])
{
    int i;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    i = 0;
    while (i < total)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        print_info(contacts[i].getFirstName());
        print_info(contacts[i].getLastName());
        print_info(contacts[i].getNickname());
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }
}

void display_searchContact(Contact contact)
{
    std::cout << "First Name:\t\t" << contact.getFirstName() << std::endl;
    std::cout << "Lasr Name:\t\t" << contact.getLastName() << std::endl;
    std::cout << "Nickname:\t\t" << contact.getNickname() << std::endl;
    std::cout << "Phone number:\t\t" << contact.getPhoneNum() << std::endl;
    std::cout << "Darkest secret:\t\t" << contact.getSecret() << std::endl;
}


void    PhoneBook::searchContact()
{
    // int i;
    int search_index;
    std::string str;

    display_all_contacts(total, contacts);
    // display_searchContact(contacts[search_index]);

    // std::cout << "---------------------------------------------" << std::endl;
    // std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    // std::cout << "---------------------------------------------" << std::endl;
    // i = 0;
    // while (i < total)
    // {
    //     std::cout << "|" << std::setw(10) << i << "|";
    //     print_info(contacts[i].getFirstName());
    //     print_info(contacts[i].getLastName());
    //     print_info(contacts[i].getNickname());
    //     std::cout << std::endl;
    //     std::cout << "---------------------------------------------" << std::endl;
    //     i++;
    // }
    std::cout << "\nEnter the index: ";
    // std::cin >> search_index;
    std::getline(std::cin, str);
    search_index = atoi(str.c_str());
    // std::cout << search_index << std::endl;
    if (isValidPhone(str) && search_index < index && search_index >= 0)
    {
        display_searchContact(contacts[search_index]);
        // std::cout << "First Name:\t\t" << contacts[search_index].getFirstName() << std::endl;
        // std::cout << "Lasr Name:\t\t" << contacts[search_index].getLastName() << std::endl;
        // std::cout << "Nickname:\t\t" << contacts[search_index].getNickname() << std::endl;
        // std::cout << "Phone number:\t\t" << contacts[search_index].getPhoneNum() << std::endl;
        // std::cout << "Darkest secret:\t\t" << contacts[search_index].getSecret() << std::endl;
    }
    else
        std::cout << "\033[31mInvalid index!\033[0m" << std::endl;
}
