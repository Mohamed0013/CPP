#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Form tax("Tax Form", 40, 30);

        std::cout << tax << std::endl;

        bob.signForm(tax);

        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
