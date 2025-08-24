#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() : name("Unnamed") {
    // optional: std::cout << "Zombie created\n";
}

// Constructor with name
Zombie::Zombie(std::string name) : name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}

// Announce
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Set name
void Zombie::setName(std::string n) {
    name = n;
}
