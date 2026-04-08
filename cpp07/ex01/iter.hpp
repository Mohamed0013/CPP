#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T *array, const int len, F f)
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}

#endif