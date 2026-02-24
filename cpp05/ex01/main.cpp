#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form f("XForm", 50, 25);
        Bureaucrat b("Hanan", 40);

        std::cout << f << std::endl;

        f.beSigned(b);

        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
