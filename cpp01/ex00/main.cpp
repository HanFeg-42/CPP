#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("malak");
    z->announce();

    randomChump("hanane");
    delete z;
}
