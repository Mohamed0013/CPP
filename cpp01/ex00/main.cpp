#include "Zombie.hpp"

// Forward declarations of helper functions
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "=== Start ===" << std::endl;
    Zombie* retZombie = newZombie("Hisoka");
    retZombie->announce();
    delete retZombie;

    std::cout << "\n=== Stack Zombie ===" << std::endl;
    randomChump("Kurulu");

    return 0;
}
