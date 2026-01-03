#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain();
	*_brain = *(other._brain);
	std::cout << "Dog copy constructor\n";
}

Dog&    Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *(other._brain);
	}
	return *this;
}
void    Dog::makeSound() const
{
	std::cout << "Bark!\n";
}

Brain	*Dog::getBrain() const
{
	return _brain;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor\n";
}
