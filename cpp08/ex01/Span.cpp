#include "Span.hpp"
#include <limits>

Span::Span()
{
    _maxSize = 0;
}

Span::Span(unsigned int N)
{
    _maxSize = N;
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_numbers.size() > _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(n);
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("There should be 2 or more numbers in your container");

    return (*std::min_element(_numbers.begin(), _numbers.end()) -  *std::max_element(_numbers.begin(), _numbers.end()));
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("There should be 2 or more numbers in your container");

    std::vector<int> tmp = _numbers;

    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

Span::~Span()
{
}