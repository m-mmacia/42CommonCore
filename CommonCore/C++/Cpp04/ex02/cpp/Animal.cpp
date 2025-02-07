#include "../hpp/Animal.hpp"

Animal::Animal(): _type("default")
{
    std::cout << "Animal default constructor." << std::endl;
}
Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor." << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal desctructor." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal '=' operator called." << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void Animal::makeSound(void)const
{
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
