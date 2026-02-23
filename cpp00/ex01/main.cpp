#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <signal.h>

void sig(int signal)
{
    if (signal == SIGINT)
        std::cout << "\n" << std::endl;
    else if (signal == SIGQUIT)
        std::cout << "\n" << std::endl;
    else if (signal == SIGTERM)
        std::cout << "\n" << std::endl;
    else
        std::cout << "\n" << signal << std::endl;
}

int main() {
    PhoneBook phonebook;
    std::string command;

    signal(SIGINT, sig);
    signal(SIGQUIT, sig);
    signal(SIGTERM, sig);
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
        {
            if (!phonebook.addContact())
                break ;
        }
        else if (command == "SEARCH")
        {
            if (!phonebook.searchContacts())
                break ;
        }
        else if (command == "EXIT")
            break;
    }
    return 0;
}