#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain();
	*_brain = *(other._brain);
	std::cout << "Cat copy constructor\n";
}

Cat&    Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *(other._brain);
	}
	return *this;
}

void    Cat::makeSound() const
{
	std::cout << "Meawwww!\n";
}

Brain	*Cat::getBrain() const
{
	return _brain;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor\n";
}
