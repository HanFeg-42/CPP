#pragma once

#include <stdint.h>
#include "Data.hpp"

//TODO
/*
* Understanding of pointers
* 
* Understanding of uintptr_t
* 
* Understanding of reinterpret_cast
* 
* Understanding of static class methods
* 
* Making a class non-instantiable
*/

class Serializer
{
private:
    Serializer();
    Serializer(Serializer& other);
    Serializer& operator=(Serializer& other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();
};

// uintptr_t is an unsigned integer type that is
// guaranteed to be large enough to store a pointer.
