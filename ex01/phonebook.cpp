#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}

void PhoneBook::printColumn(const std::string &str) const {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

void PhoneBook::addContact() {
    Contact c;
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    if (!c.setFirstName(input)) return;

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    if (!c.setLastName(input)) return;

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    if (!c.setNickname(input)) return;

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    if (!c.setPhoneNumber(input)) return;

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    if (!c.setDarkestSecret(input)) return;

    contacts[oldestIndex] = c;
    oldestIndex = (oldestIndex + 1) % 8;
    if (totalContacts < 8) totalContacts++;

    std::cout << "Contact added!\n";
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "No contacts yet.\n";
        return;
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

    std::cout << "Enter index to view details: ";
    int index;
    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid index.\n";
        return;
    }
    if (index < 0 || index >= totalContacts) {
        std::cout << "Invalid index.\n";
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";

}
