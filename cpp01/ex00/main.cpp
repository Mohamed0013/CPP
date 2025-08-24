#include "Zombie.hpp"

// Forward declarations of helper functions
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "=== returned Zombie ===" << std::endl;
    Zombie* retZombie = newZombie("Mohamed");
    retZombie->announce();
    delete retZombie; // must delete to avoid leak

    std::cout << "\n=== Stack Zombie ===" << std::endl;
    randomChump("Stacky");

    return 0;
}
