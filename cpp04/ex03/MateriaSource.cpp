#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		slots[i] = other.slots[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			slots[i] = other.slots[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i;
	for (i = 0; i < 4 && slots[i]; i++);
	if (i < 4)
		slots[i] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && slots[i]; i++)
		if (slots[i]->getType() == type)
			return (slots[i]->clone());
	return (NULL);
}

MateriaSource::~MateriaSource() {

}
