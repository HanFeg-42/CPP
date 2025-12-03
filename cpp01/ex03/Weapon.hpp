#ifndef _WEAPON_H_
# define _WEAPON_H_

# include <iostream>
# include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string _type);
    Weapon();

    const std::string   &getType() const;
    void                setType(const std::string &new_type);
};

#endif