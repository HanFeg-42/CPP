#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//subject tests
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	// My tests
	Animal *animals[4] = {
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};
	std::cout << std::endl;
	
	animals[0]->makeSound();
	animals[2]->makeSound();
	std::cout << std::endl;
	
	Cat c;
	Dog d;
	c.getBrain()->setIdea(0, "I'm just a Cat");
	d.getBrain()->setIdea(0, "I want to eat");
	std::cout << c.getBrain()->getIdea(0) << std::endl;
	std::cout << d.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Deep copy test
	Cat a(c);
	std::cout << std::endl;
	if (a.getBrain() != c.getBrain())
		std::cout << "Diffrent Brain adresses" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << std::endl;
}
