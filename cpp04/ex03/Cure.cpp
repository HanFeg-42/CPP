#pragma once

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure & other) : AMateria(other)
{
}

Cure & Cure::operator=(const Cure & other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

Cure::~Cure()
{
}
