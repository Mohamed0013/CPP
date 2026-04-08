#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error("number not found");
    
    return (it);
}
