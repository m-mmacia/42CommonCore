#include "../hpp/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	std::cout << "WrongCat copy constructor." << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat '=' operator." << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void WrongCat::makeSound(void)const
{
	std::cout << this->getType() << " : WrongCat sound" << std::endl;
}
