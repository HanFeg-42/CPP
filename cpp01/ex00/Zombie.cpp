#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
    _name = name;
}

Zombie::~Zombie( void )
{
    std::cout << _name << " Died owwwwwwwwwwww!\n";
}

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
