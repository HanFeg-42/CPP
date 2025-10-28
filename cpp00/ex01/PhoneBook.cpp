#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

// PhoneBook::PhoneBook()
// {
//     index = 0;
// }

void    PhoneBook::add_contact()
{
    contacts[index].set_info();
    index = (index + 1) % 8;
}

void    print_info(std::string str)
{
    if (str.length() >= 10)
        std::cout << str.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << str << "|";
}

void    PhoneBook::search_contact()
{
    int i;
    int search_index;

    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    i = 0;
    while (i < index)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        print_info(contacts[i].first_name);
        print_info(contacts[i].last_name);
        print_info(contacts[i].nickname);
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }
    std::cout << "\nEnter the index:";
    std::cin >> search_index;
    if (search_index <= index && search_index >= 0)
    {
        std::cout << "First Name:\t\t" << contacts[search_index].first_name << std::endl;
        std::cout << "Lasr Name:\t\t" << contacts[search_index].last_name << std::endl;
        std::cout << "Nickname:\t\t" << contacts[search_index].nickname << std::endl;
        std::cout << "Phone number:\t\t" << contacts[search_index].phone_num << std::endl;
        std::cout << "Darkest secret:\t\t" << contacts[search_index].secret << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}

void    PhoneBook::exit_app()
{
    exit(0);
}
