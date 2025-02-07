#include "../hpp/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
		exit(1);
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog copy." << std::endl;
	*this = copy;
}
Dog::~Dog()
{
	delete(this->_brain);
	std::cout << "Dog destructor." << std::endl;
}
Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog '=' operator." << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
		exit(1);
	*this->_brain = *src._brain;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << " : WoOof" << std::endl;
}

void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "Idea " << i << " of the dog :" << this->_brain->getIdea(i) << " address :" << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}