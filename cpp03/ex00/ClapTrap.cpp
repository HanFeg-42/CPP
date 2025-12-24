#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
    _hitPoint(10),
    _energyPoint(10),
    _attackDamage(0)
{}

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hitPoint(10),
    _energyPoint(10),
    _attackDamage(0)
{}

ClapTrap::ClapTrap(const ClapTrap& other) : 
    _name(other._name),
    _hitPoint(other._hitPoint),
    _energyPoint(other._energyPoint),
    _attackDamage(other._attackDamage)
{}


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
    _energyPoint--;
    if (_hitPoint <= 0)
    {
        std::cout << "No hit points left!\n";
        return ;
    }
    if (_energyPoint <= 0)
    {
        std::cout << "No energy points left!\n";
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}
void    ClapTrap::takeDamage(unsigned int amount)
{
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    _energyPoint--;

}

ClapTrap::~ClapTrap() {}