#pragma once

#include <stdint.h>
#include "Data.hpp"

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
