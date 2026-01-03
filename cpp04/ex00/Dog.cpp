#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor\n";
}

Dog&    Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void    Dog::makeSound() const
{
	std::cout << "Dog Barks!\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor\n";
}
