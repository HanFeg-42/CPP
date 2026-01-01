#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << _name << " FragTrap Parameterized constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << _name << " FragTrap Copy constructor called\n";
}


FragTrap&   FragTrap::operator=(const FragTrap& other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap is requesting a high five! ✋ Positive vibes only!" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " Destructor called\n";
}
