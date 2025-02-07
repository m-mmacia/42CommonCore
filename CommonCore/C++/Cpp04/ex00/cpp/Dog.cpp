#include "../hpp/Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor." << std::endl;
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog copy constructor." << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor." << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog '=' assignation." << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << " : WoOof" << std::endl;
}
