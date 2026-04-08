#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private:
        T   *_array;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        Array &operator=(Array const &other);
        ~Array();

        T   &operator[](unsigned int index);
        T const &operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Array index out of bounds";
                }
        };
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other): _array(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        if (_size == 0)
        {
            _array = NULL;
            return (*this);
        }
        _array = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}


#endif