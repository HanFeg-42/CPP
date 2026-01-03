#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria constructor\n";
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor\n";
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << "AMateria constructor\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
}

AMateria::~AMateria()
{
		std::cout << "AMateria destructor\n";
}
