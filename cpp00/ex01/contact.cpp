#include "contact.hpp"
#include <string>
#include <sstream>

static std::string trim(const std::string &s) {
    size_t start = 0;
    while (start < s.size() && std::isspace((unsigned char)s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace((unsigned char)s[end - 1]))
        end--;

    return s.substr(start, end - start);
}

bool Contact::setFirstName(const std::string &f) {
    std::string trimmed = trim(f);
    if (trimmed.empty())
        return false;
    for (size_t i = 0; i < trimmed.length(); i++)
    {
        if (!std::isalpha(trimmed[i]))
            return false;
    }
    firstName = trimmed;
    return true;
}

bool Contact::setLastName(const std::string &l) {
    std::string trimmed = trim(l);
    if (trimmed.empty())
        return false; 
    for (size_t i = 0; i < trimmed.length(); i++)
    {
        if (!std::isalpha(trimmed[i]))
            return false;
    }
    lastName = trimmed;
    return true;
}

bool Contact::setNickname(const std::string &n) {
    std::string trimmed = trim(n);
    if (trimmed.empty())
        return false; 
    nickname = trimmed;
    return true;
}

bool Contact::setPhoneNumber(const long &p) {
    if (p <= 0)
        return false;
    phoneNumber = p;
    return true;
}

bool Contact::setDarkestSecret(const std::string &d) {
    std::string trimmed = trim(d);
    if (trimmed.empty())
        return false;
    darkestSecret = trimmed;
    return true;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
long Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
