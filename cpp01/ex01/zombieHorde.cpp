#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;
    Zombie *zombies = new Zombie[N];
    i = 0;
    while (i < N)
    {
        zombies[i].setName(name);
        i++;
    }
    return (zombies);
}
