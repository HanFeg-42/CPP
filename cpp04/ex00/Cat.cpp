#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor\n";
}

Cat&    Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}
void    Cat::makeSound() const
{
    std::cout << "Meawwww!\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor\n";
}
