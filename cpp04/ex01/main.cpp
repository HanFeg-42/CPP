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
//     std::cout << "----- TEST 1: Copy constructor deep copy -----\n";

//     Cat original;
//     original.getBrain()->setIdea(0, "I want fish");

//     Cat copy(original);

//     std::cout << "Original idea: "
//               << original.getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copy idea: "
//               << copy.getBrain()->getIdea(0) << std::endl;

//     original.getBrain()->setIdea(0, "I want sleep");
//     copy.getBrain()->setIdea(0, "I want milk");

//     std::cout << "After modification:\n";
//     std::cout << "Original idea: "
//               << original.getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copy idea: "
//               << copy.getBrain()->getIdea(0) << std::endl;


//     std::cout << "\n----- TEST 2: Assignment operator deep copy -----\n";

//     Cat a;
//     Cat b;

//     a.getBrain()->setIdea(0, "I want milk");
//     b = a;

//     std::cout << "A idea: "
//               << a.getBrain()->getIdea(0) << std::endl;
//     std::cout << "B idea: "
//               << b.getBrain()->getIdea(0) << std::endl;

//     b.getBrain()->setIdea(0, "I want to play");

//     std::cout << "After modification:\n";
//     std::cout << "A idea: "
//               << a.getBrain()->getIdea(0) << std::endl;
//     std::cout << "B idea: "
//               << b.getBrain()->getIdea(0) << std::endl;


//     std::cout << "\n----- TEST 3: Destructor safety -----\n";

//     {
//         Cat temp1;
//         Cat temp2(temp1);
//     }

//     std::cout << "End of tests\n";
//     return 0;
// }
