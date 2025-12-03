#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
    _name = name;
}

Zombie::Zombie( void )
{

}

Zombie::~Zombie( void )
{
    std::cout << _name << " Died owwwwwwwwwwww!\n";
}

void    Zombie::setName( std::string name )
{
    _name = name;
}

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
