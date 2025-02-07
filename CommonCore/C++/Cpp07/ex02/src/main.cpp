#include "../includes/Array.hpp"

//empty array create by default constructor
void	empty_array()
{
	std::cout << "test - empty_array" << std::endl;
	Array<int> array;
	std::cout << "array.size = " << array.size() << std::endl;
	std::cout << std::endl;
}

//create array with 'i' rows, because i cast <int> at my Array (template) we will create 'int' array
void	create_array_empty(int i)
{
	std::cout << "test - create_array" << std::endl;
	Array<int> array(i);
	std::cout << "array.size = " << array.size() << std::endl;
	for (int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}
//create array with int value in rows
void	create_array_int()
{
	std::cout << "test - create_array_int" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	for (int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}
//create array with char value in rows
void	create_array_char()
{
	std::cout << "test - create_array_char" << std::endl;
	Array<char> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 'a';
	array[1] = 'b';
	array[2] = 'c';
	for (int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}
//create array and try to acced invalid rows 
void	create_array_invalid()
{
	std::cout << "test - create_array_invalid" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	for (int i = 0; i < 5; i++)
	{
		try {
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}
//constructor copy
void	copy_constructor()
{
	std::cout << "test - copy_constructor" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	Array<int> array2(array);
	std::cout << "array2.size = " << array2.size() << std::endl;
	for (int i = 0; i < array2.size(); i++)
		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
	std::cout << "Change array[0] = 42" << std::endl;
	array[0] = 42;
	std::cout << "array[0] = " << array[0] << std::endl;
	std::cout << "array2[0] = " << array2[0] << std::endl;
	std::cout << std::endl;
}
//overload test '='
void	overload_assignation()
{
	std::cout << "test - overload_assignation" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	Array<int> array2 = array;
	std::cout << "array2.size = " << array2.size() << std::endl;
	for (int i = 0; i < array2.size(); i++)
		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
	std::cout << "Change array[0] = 42" << std::endl;
	array[0] = 42;
	std::cout << "array[0] = " << array[0] << std::endl;
	std::cout << "array2[0] = " << array2[0] << std::endl;
	std::cout << std::endl;
}

int main(int, char**)
{
	empty_array();
	create_array_empty(3);
	create_array_int();
	create_array_char();
	create_array_invalid();
	copy_constructor();
	overload_assignation();
}
