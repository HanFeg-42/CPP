#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void)
{
    int rand = std::rand();
    if (rand % 3 == 0)
        return new A;
    if (rand % 3 == 1)
        return new B;
    return new C;
    
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    if (dynamic_cast<C *>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
    {
      (void) dynamic_cast<A&>(p);
        
        std::cout << "A\n";
    }
    catch(const std::exception& e) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B\n";
    }
    catch(const std::exception& e) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C\n";
    }
    catch(const std::exception& e) {}
}

int main()
{
    std::srand(time(0));

    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;
}
