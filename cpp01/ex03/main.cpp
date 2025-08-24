#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("Lbanan");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("Tfa7");
        bob.attack();
    }
    {
        Weapon club = Weapon("Limon");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("L3asser");
        jim.attack();
    }
    return 0;
}
