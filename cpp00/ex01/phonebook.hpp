#ifndef PHONEBOOK_HPP 
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    int oldestIndex;

    void printColumn(const std::string &str) const;

public:
    PhoneBook();
    bool addContact();
    bool searchContacts() const;
};

#endif
