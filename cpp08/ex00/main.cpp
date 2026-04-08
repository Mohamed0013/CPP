#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        easyfind(v, 20);
        std::cout << "20 found in vector\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(v, 50);
        std::cout << "50 found\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        easyfind(l, 2);
        std::cout << "2 found in list\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(l, 7);
        std::cout << "7 found in list\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}