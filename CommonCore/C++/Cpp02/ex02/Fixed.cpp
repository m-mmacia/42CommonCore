/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:49 by mmacia            #+#    #+#             */
/*   Updated: 2024/09/16 14:26:55 by mmacia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"


Fixed::Fixed() : _save_float(0){
}

Fixed::~Fixed(){
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	return o << i.toFloat();
}

Fixed::Fixed (const int num)
{
    _save_float = num << _save_bits;
}

Fixed::Fixed (const float num)
{
    _save_float = round(num * (1 << _save_bits));
}

Fixed::Fixed (const Fixed &Fixcpy)
{
    *this = Fixcpy;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _save_float = other.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    _save_float = raw;
}

int Fixed::getRawBits() const
{
    return _save_float;
}

int Fixed::toInt(void) const
{
    return _save_float << _save_bits;
}

// -- operator
bool Fixed::operator>(Fixed fixed) const
{
    return getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(Fixed fixed) const
{
    return getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(Fixed fixed) const
{
    return getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(Fixed fixed) const
{
    return getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(Fixed fixed) const
{
    return getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(Fixed fixed) const
{
    return getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(Fixed fixed)const
{
    return Fixed(toFloat() + fixed.toFloat());
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_save_float) / (1 << _save_bits);
}


Fixed Fixed::operator-(Fixed fixed)const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed fixed)const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed fixed)const
{
    return Fixed(toFloat() * fixed.toFloat());
}

// pre-increment 
Fixed &Fixed::operator++(void)
{
    _save_float += 1;
    return *this;
}

// post-increment 
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _save_float += 1;
    return temp;
}

// pre-decrement
Fixed &Fixed::operator--(void)
{
    _save_float -= 1;
    return *this;
}

// post-decrement
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _save_float -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}

