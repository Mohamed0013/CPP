#include "Zombie.hpp"

int main() {
    int N = 5; // size of the horde

    // Create a horde of 5 zombies named "HordeZombie"
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce(); // each announces itself
        }

        // Clean up memory
        delete[] horde;
    }

    return 0;
}
