#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* _array;
        int _size;
    public:
        Array();
        Array(int n);
        Array(const Array& copy);
        ~Array();
        Array& operator=(const Array& copy);
        T& operator[](int index);
		int size() const;

    class outOfRange : public std::exception
        {
        public:
            virtual const char* what() const throw() {
                return "Out of range";
            }
        };
};

#include "Array.tpp"