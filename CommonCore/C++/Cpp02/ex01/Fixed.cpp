/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:25:47 by mmacia            #+#    #+#             */
/*   Updated: 2024/09/16 14:25:51 by mmacia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

Fixed::Fixed() : _save_float(0) {
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed (const Fixed &Fixcpy) : _save_float(Fixcpy._save_float) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _save_float(num << _save_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _save_float(roundf(num * (1 << _save_bits))) {
    std::cout << "Float constructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getARawBits called" << std::endl;
    return this->_save_float;
}

int Fixed::toInt(void) const {
    std::cout << "toInt called" << std::endl;
    return _save_float >> _save_bits;
}

float Fixed::toFloat(void) const {
    std::cout << "toFloat called" << std::endl;
    return (float)_save_float / (1 << _save_bits);
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

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	return o << i.toFloat();
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}

