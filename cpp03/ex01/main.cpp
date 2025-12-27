#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("naruto");
    ClapTrap b("sasuki");

    a.attack("sasuki");
    b.beRepaired(10);
    a.takeDamage(5);

    return 0;
}