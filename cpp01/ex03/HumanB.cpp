#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : w(NULL), name(_name)
{
}

void    HumanB::attack() const
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &_w)
{
    w = &_w;
}
