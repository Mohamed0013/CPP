#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    bool setFirstName(const std::string &f);
    bool setLastName(const std::string &l);
    bool setNickname(const std::string &n);
    bool setPhoneNumber(const std::string &p);
    bool setDarkestSecret(const std::string &d);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
