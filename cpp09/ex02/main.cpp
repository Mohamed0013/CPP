#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: no input provided" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe p;
        p.parse(ac, av);
        p.sort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}