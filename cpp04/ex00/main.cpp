#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;
    return 0;
}


// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat();

//     std::cout << i->getType() << " " << std::endl;
//     meta->makeSound();
//     i->makeSound(); //will output the WrongAnima sound!

//     delete i;
//     delete meta;
//     return 0;
// }
