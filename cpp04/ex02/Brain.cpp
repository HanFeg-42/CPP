#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string const Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return "";
	return ideas[idx];
}

void Brain::setIdea(int idx, std::string const &idea)
{
	if (idx >= 0 && idx < 100)
		ideas[idx] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain destructor\n";
}
