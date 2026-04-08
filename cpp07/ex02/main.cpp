#include <string>
#include "Array.hpp"

int main(void)
{
    // Test 1: default constructor
    std::cout << "--- Default constructor ---" << std::endl;
    Array<int> empty;
    std::cout << "size = " << empty.size() << std::endl;

    // Test 2: size constructor with int
    std::cout << "\n--- Size constructor (int) ---" << std::endl;
    Array<int> ints(5);
    std::cout << "size = " << ints.size() << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    // Test 3: fill and read back
    std::cout << "\n--- Fill array ---" << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = (int)i * 10;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    // Test 4: copy constructor
    std::cout << "\n--- Copy constructor ---" << std::endl;
    Array<int> copy(ints);
    copy[0] = 999;
    std::cout << "copy[0]  = " << copy[0] << std::endl;
    std::cout << "ints[0]  = " << ints[0] << std::endl;

    // Test 5: assignment operator
    std::cout << "\n--- Assignment operator ---" << std::endl;
    Array<int> assigned;
    assigned = ints;
    assigned[1] = 777;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;
    std::cout << "ints[1]     = " << ints[1] << std::endl;

    // Test 6: string array
    std::cout << "\n--- String array ---" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "templates";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << "strs[" << i << "] = " << strs[i] << std::endl;

    // Test 7: out of bounds exception
    std::cout << "\n--- Out of bounds exception ---" << std::endl;
    try
    {
        std::cout << ints[999] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test 8: empty array access
    std::cout << "\n--- Empty array access ---" << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}