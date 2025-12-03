#ifndef _HUMANB_H_
#define _HUMANB_H_

# include "Weapon.hpp"

class HumanB
{
private:
    Weapon      *w;
    std::string name;
public:
    HumanB(std::string _name);

    void    attack() const;
    void    setWeapon(Weapon &_w);
};

#endif