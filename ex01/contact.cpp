#include "contact.hpp"

Contact::Contact() {}

bool Contact::setFirstName(const std::string &f) {
    if (f.empty()) return false;
    firstName = f;
    return true;
}

bool Contact::setLastName(const std::string &l) {
    if (l.empty()) return false;
    lastName = l;
    return true;
}

bool Contact::setNickname(const std::string &n) {
    if (n.empty()) return false;
    nickname = n;
    return true;
}

bool Contact::setPhoneNumber(const std::string &p) {
    if (p.empty()) return false;
    phoneNumber = p;
    return true;
}

bool Contact::setDarkestSecret(const std::string &d) {
    if (d.empty()) return false;
    darkestSecret = d;
    return true;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
