#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{ 
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);

    MateriaSource& oparator=(const MateriaSource& other);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

    ~MateriaSource();
};
