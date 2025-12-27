#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << _name << " ScavTrap Parameterized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << _name << " ScavTrap Copy constructor called\n";
}


ScavTrap&   ScavTrap::operator=(const ScavTrap& other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void	ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

void    ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " Can't attack! No HP left!\n";
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " Can't attack! No energy points left!\n";
        return ;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " Destructor called\n";
}
