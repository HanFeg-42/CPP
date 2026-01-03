#pragma once

#include <iostream>

class Brain
{
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);

	Brain& operator=(const Brain& other);
	std::string const getIdea(int idx) const;
	void setIdea(int idx, std::string const &idea);

	~Brain();
};
