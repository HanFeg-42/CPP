#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);

	WrongAnimal& 		operator=(const WrongAnimal& other);
	const std::string&	getType() const;
	void				makeSound() const;

	~WrongAnimal();
};

