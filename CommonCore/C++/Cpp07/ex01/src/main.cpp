#include "../include/iter.hpp"

void mySuparFunction(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

int main(void)
{
    char array[] = {'a', 'b', 'c', 'd'};
    int size = sizeof(array) / sizeof(array[0]);

    //iter template 
    ::iter(array, size, mySuparFunction);

    for (int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;   
}