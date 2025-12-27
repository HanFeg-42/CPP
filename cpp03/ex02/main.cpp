#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("naruto");
    ScavTrap b("sasuki");

    a.attack("sasuki");
    b.beRepaired(10);
    a.takeDamage(5);

    return 0;
}