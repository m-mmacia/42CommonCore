#include "Fixed.hpp"

Fixed::Fixed() : _save_float(0) {
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed (const Fixed &Fixcpy) : _save_float(Fixcpy._save_float) {
    std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return this->_save_float;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called" << std::endl;
    this->_save_float = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        std::cout << "Surcharge called" << std::endl;
        this->_save_float = other._save_float;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}

