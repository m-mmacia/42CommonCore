#include "../hpp/Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor." << std::endl;
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat copy constructor." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor." << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat '=' operator." << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " : MeEeEoOw" << std::endl;
}