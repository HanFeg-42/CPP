#include "Bureaucrat.hpp"

int main()
{
    //TODO: <name>, bureaucrat grade <grade>.
    try {
        Bureaucrat("Hmed", -1);
    }
    catch  (std::exception & e)
    {
        std::cout << e << std::endl;
    }
}