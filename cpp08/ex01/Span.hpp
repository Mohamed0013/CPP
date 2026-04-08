#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Span capacity exceeded");

        _numbers.insert(_numbers.end(), begin, end);
    }
};
