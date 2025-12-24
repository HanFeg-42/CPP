#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoint(10), _energyPoint(10), _attackDamage(0) {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    
}
void    ClapTrap::takeDamage(unsigned int amount);
void    ClapTrap::beRepaired(unsigned int amount);

ClapTrap::~ClapTrap() {}