#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::vector<int> v;

    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    Span sp2(10);

    sp2.addNumbers(v.begin(), v.end());

    std::cout << "Shortest span sp2: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span sp2: " << sp2.longestSpan() << std::endl;

    return 0;
}