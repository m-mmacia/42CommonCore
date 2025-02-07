#pragma once

#include <iostream>

template <typename T>

void iter(T *array, int size, void (*f)(T &))
{
    if (!array)
        return ;
    for (int i = 0; i < size; i++)
        f(array[i]);
}