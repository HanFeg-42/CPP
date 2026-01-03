#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) 
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character & other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (other._inventory[i] == NULL)
				_inventory[i] = NULL;
			else
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
		return;
	while (i < 4 && _inventory[i] != NULL)
		i++;
	if (i < 4)
		_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >=0 && idx < 4)
		if (_inventory[idx])
			_inventory[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}
