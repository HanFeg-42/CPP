#ifndef _ZOMBIE_H_
# define _ZOMBIE_H_

# include <iostream>
# include <string>

class Zombie {
    std::string _name;
public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie( void );
    void setName( std::string name );
    void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif