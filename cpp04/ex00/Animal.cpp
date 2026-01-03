#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor\n";
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sound\n";
}

const std::string&	Animal::getType() const
{
	return _type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}
