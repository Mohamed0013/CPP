#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return nullptr;

    Zombie* horde = new Zombie[N];  // one allocation for N zombies
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);     // assign the same name to each zombie
    }
    return horde; // return pointer to the first zombie
}
