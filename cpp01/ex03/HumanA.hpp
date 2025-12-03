#ifndef _HUMANA_H_
# define _HUMANA_H_

# include "Weapon.hpp"

class HumanA
{
private:
    Weapon      &w;
    std::string name;
public:
    HumanA(std::string _name, Weapon &_w);

    void    attack() const;
};

#endif