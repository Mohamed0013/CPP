#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();                     // default constructor
    Zombie(std::string name);     // constructor with name
    ~Zombie();                    // destructor

    void announce() const;        // announce the zombie
    void setName(std::string n);  // setter for name
};

Zombie* zombieHorde(int N, std::string name);

#endif
