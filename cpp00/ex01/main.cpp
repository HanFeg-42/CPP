#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "\033[1;35mphonebook->\033[0m";
        std::getline(std::cin, cmd);
        if (std::cin.eof() || std::cin.fail())
            break;
        if (cmd.compare("ADD") == 0)
            pb.add_contact();
        else if (cmd.compare("SEARCH") == 0)
            pb.search_contact();
        else if (cmd.compare("EXIT") == 0)
            pb.exit_app();
        else
            std::cout << "Unvalid command!\n";
    }
}