#pragma once

class Serializer
{
private:
    Serializer();
    Serializer(Serializer& other);
    Serializer& operator=(Serializer& other);
public:
    ~Serializer();
};

