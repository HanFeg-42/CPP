#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_w) : w(_w), name(_name)
{
}

void    HumanA::attack() const
{
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}
