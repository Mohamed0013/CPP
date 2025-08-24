#include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";

    std::string* stringPTR = &s;

    std::string& stringREF = s;

    std::cout << "The memory address of the string variable: ";
    std::cout << &s << std::endl;

    std::cout << "The memory address held by stringPTR: ";
    std::cout << stringPTR << std::endl;

    std::cout << "The memory address held by stringREF: ";
    std::cout << &stringREF << std::endl;

    std::cout << "The value of the string variable: ";
    std::cout << s << std::endl;

    std::cout << "The value pointed to by stringPTR: ";
    std::cout << *stringPTR << std::endl;

    std::cout << "The value pointed to by stringREF: ";
    std::cout << stringREF << std::endl;

    return (0);
}