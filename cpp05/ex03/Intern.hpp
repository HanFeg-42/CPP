#pragma once
#include <iostream>
#include <exception>
class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string const name, std::string const target) const;
};
