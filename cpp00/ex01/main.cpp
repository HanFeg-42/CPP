#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    // std::cout << "\033[1;35m__phonebook__\033[0m";
    while (1)
    {
        std::cout << "\033[1;35mEnter a command ADD, SEARCH or EXIT: \033[0m";
        std::getline(std::cin, cmd);
        if (std::cin.eof() || std::cin.fail())
            break;
        if (cmd.compare("ADD") == 0)
            pb.addContact();
        else if (cmd.compare("SEARCH") == 0)
            pb.searchContact();
        else if (cmd.compare("EXIT") == 0)
            break ;
        else
            std::cout << "\033[31mInvalid command!\033[0m\n";
    }
}