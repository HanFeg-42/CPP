#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor\n";
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void    WrongCat::makeSound() const
{
	std::cout << "WrongCat sound!\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor\n";
}
