#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), total(0) {}

void    PhoneBook::addContact()
{
    contacts[index].setInfo();
    index = (index + 1) % 8;
    if (total < 8)
        total++;
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
        contacts[i].displaySavedContact();
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }
}

void    PhoneBook::searchContact()
{
    int search_index;
    std::string str;

    display_all_contacts(total, contacts);
    std::cout << "\nEnter the index: ";
    std::getline(std::cin, str);
    search_index = atoi(str.c_str());
    if (isValidPhone(str) && search_index < total && search_index >= 0)
        contacts[search_index].displaySearchContact();
    else
        std::cout << "\033[31mInvalid index!\033[0m" << std::endl;
}

void    PhoneBook::start()
{
    std::string cmd;

    while (1)
    {
        std::cout << "\033[1;35mEnter a command ADD, SEARCH or EXIT: \033[0m";
        std::getline(std::cin, cmd);
        if (std::cin.eof() || std::cin.fail())
            break;
        if (cmd.compare("ADD") == 0)
            addContact();
        else if (cmd.compare("SEARCH") == 0)
            searchContact();
        else if (cmd.compare("EXIT") == 0)
            break ;
        else
            std::cout << "\033[31mInvalid command!\033[0m\n";
    }
}
