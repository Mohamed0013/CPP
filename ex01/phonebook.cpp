#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}

void PhoneBook::printColumn(const std::string &str) const {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

bool PhoneBook::addContact() {
    Contact c;
    std::string input;\
    
    while (1) {
        std::cout << "First name: ";
        if (!std::getline(std::cin, input)) {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cout << "\nInput cancelled.\n";
                return false;   // stop add, go back to main menu
            }
        }
        if (c.setFirstName(input))
            break;
        else
            std::cout << "Invalid Name !" << std::endl;
    }
    while (1)
    {
        std::cout << "Last name: ";
        if (!std::getline(std::cin, input)) { // Ctrl+D pressed
            std::cout << "\nInput cancelled.\n";
            return false;
        }
        if (c.setLastName(input))
            break ;
        else
            std::cout << "Invalid Name !" << std::endl;
    }
    while (1)
    {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input)) { // Ctrl+D pressed
            std::cout << "\nInput cancelled.\n";
            return false;
        }
        if (c.setNickname(input))
            break ;
        else
            std::cout << "Can not be empty !" << std::endl;
    }
    while (1)
    {
        std::cout << "Phone number: ";
        if (!std::getline(std::cin, input)) { // Ctrl+D pressed
            std::cout << "\nInput cancelled.\n";
            return false;
        }
        bool valid = true;
        for (size_t i = 0; i < input.size(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = false;
                break;
            }
        }

        if (valid && c.setPhoneNumber(atol(input.c_str())))
            break;
        else
            std::cout << "Invalid phone number!" << std::endl;
    }
    while (1)
    {
        std::cout << "Darkest secret: ";
        if (!std::getline(std::cin, input)) { // Ctrl+D pressed
            std::cout << "\nInput cancelled.\n";
            return false;
        }
        if (c.setDarkestSecret(input))
            break ;
        else
            std::cout << "Can not be empty !" << std::endl;
    }

    contacts[oldestIndex] = c;
    oldestIndex = (oldestIndex + 1) % 8;
    if (totalContacts < 8) totalContacts++;

    std::cout << "Contact added!\n";
    return true;
}

bool PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "No contacts yet.\n";
        return true;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << i << "|";
        printColumn(contacts[i].getFirstName());
        std::cout << "|";
        printColumn(contacts[i].getLastName());
        std::cout << "|";
        printColumn(contacts[i].getNickname());
        std::cout << "\n";
    }
    int index;
    while (1)
    {
        std::cout << "Enter index to view details: ";

        if (!(std::cin >> index)) {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cout << "\nSearch cancelled.\n";
                return false;
            }
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // flush bad input
            std::cout << "Invalid index.\n";
            continue ;
        }
        std::cin.ignore(10000, '\n'); // IMPORTANT: clear leftover newline
        if (index < 0 || index >= totalContacts) {
            std::cout << "Invalid index.\n";
            continue ;
        }
        break ;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
    return true;
}
