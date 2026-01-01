#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    _name(other._name),
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " Copy constructor called\n";
}


ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " Can't attack! No HP left!\n";
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " Can't attack! No energy points left!\n";
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints >= amount)
        _hitPoints -= amount;
    else
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes "
        << amount << " points of damage!\n";
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << "Can't be repaired! No HP left!\n";
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << "Can't be repaired! No energy points left!\n";
        return ;
    }
    std::cout << "ClapTrap " << _name << " gains "
        << amount << " hit points!\n";
    _energyPoints--;
    _hitPoints += amount;

}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap "<< _name << " Destructor called\n";
}
