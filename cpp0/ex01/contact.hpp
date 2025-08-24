#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    long phoneNumber;
    std::string darkestSecret;

public:
    bool setFirstName(const std::string &f);
    bool setLastName(const std::string &l);
    bool setNickname(const std::string &n);
    bool setPhoneNumber(const long &p);
    bool setDarkestSecret(const std::string &d);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    long getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
