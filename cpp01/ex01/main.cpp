#include "Zombie.hpp"

int main()
{
    Zombie *z1 = zombieHorde(5, "hanane");
    Zombie *z2 = zombieHorde(5, "zombie");
    int i = 0;
    while (i < 5)
    {
        z1[i].announce();
        z2[i].announce();
        i++;
    }
    delete[] z1;
    delete[] z2;
    return (0);
}
