#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    return 0;
}

// int main()
// {
// 	std::cout << "===== BASIC POLYMORPHISM TEST =====" << std::endl;
// 	{
// 		const Animal* a = new Dog();
// 		const Animal* b = new Cat();

// 		std::cout << a->getType() << std::endl;
// 		std::cout << b->getType() << std::endl;

// 		a->makeSound();
// 		b->makeSound();

// 		delete a;
// 		delete b;
// 	}

// 	std::cout << "\n===== DEEP COPY TEST (COPY CONSTRUCTOR) =====" << std::endl;
// 	{
// 		Cat original;
// 		original.getBrain()->setIdea(0, "I want fish");

// 		Cat copy(original);

// 		std::cout << "Original idea: "
// 		          << original.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "Copy idea: "
// 		          << copy.getBrain()->getIdea(0) << std::endl;

// 		copy.getBrain()->setIdea(0, "I want sleep");

// 		std::cout << "After modification:" << std::endl;
// 		std::cout << "Original idea: "
// 		          << original.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "Copy idea: "
// 		          << copy.getBrain()->getIdea(0) << std::endl;
// 	}

// 	std::cout << "\n===== DEEP COPY TEST (ASSIGNMENT OPERATOR) =====" << std::endl;
// 	{
// 		Cat a;
// 		Cat b;

// 		a.getBrain()->setIdea(0, "I want milk");

// 		b = a;

// 		std::cout << "A idea: "
// 		          << a.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "B idea: "
// 		          << b.getBrain()->getIdea(0) << std::endl;

// 		b.getBrain()->setIdea(0, "I want to play");

// 		std::cout << "After modification:" << std::endl;
// 		std::cout << "A idea: "
// 		          << a.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "B idea: "
// 		          << b.getBrain()->getIdea(0) << std::endl;
// 	}

// 	std::cout << "\n===== ARRAY OF ANIMALS TEST =====" << std::endl;
// 	{
// 		const Animal* animals[4];

// 		animals[0] = new Dog();
// 		animals[1] = new Dog();
// 		animals[2] = new Cat();
// 		animals[3] = new Cat();

// 		for (int i = 0; i < 4; i++)
// 			animals[i]->makeSound();

// 		for (int i = 0; i < 4; i++)
// 			delete animals[i];
// 	}

// 	std::cout << "\n===== END OF TESTS =====" << std::endl;
// 	return 0;
// }
