#include "../hpp/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
		exit(1);
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat copy constructor." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	delete(this->_brain);
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