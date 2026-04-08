#include <iostream>
#include <string>
#include "iter.hpp"


template <typename T>
void print(T const &elem)
{
    std::cout << elem << " ";
}

void increment(int &elem)
{
    elem++;
}

void printDouble(int const &elem)
{
    std::cout << elem * 2 << " ";
}

int main(void)
{
    // Test 1: int array with a modifying function
    std::cout << "--- int array: increment then print ---" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;

    ::iter(arr, len, increment);
    ::iter(arr, len, print<int>);
    std::cout << std::endl;

    // Test 2: string array with a print template
    std::cout << "--- string array: print ---" << std::endl;
    std::string words[] = {"hello", "my", "templates"};
    ::iter(words, 3, print<std::string>);
    std::cout << std::endl;

    // Test 3: const array → function must take const reference
    std::cout << "--- const int array: printDouble ---" << std::endl;
    const int consts[] = {10, 20, 30};
    ::iter(consts, 3, printDouble);
    ::iter(consts, 3, print<int>);
    std::cout << std::endl;

    // Test 4: char array
    std::cout << "--- char array: print ---" << std::endl;
    char letters[] = {'A', 'B', 'C', 'D'};
    ::iter(letters, 4, print<char>);
    std::cout << std::endl;

    return 0;
}