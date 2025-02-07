#include "../hpp/WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("wrong_default")
{
	std::cout << "WrongAnimal default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor." << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal '=' assignation." << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << " : WrongAnimal bruh" << std::endl;
}

std::string	WrongAnimal::getType(void)const
{
	return (this->_type);
}
