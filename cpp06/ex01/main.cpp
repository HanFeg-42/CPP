#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data obj(8);
    Data* ptr = &obj;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* restored = Serializer::deserialize(raw);
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Restored pointer: " << restored << std::endl;
}