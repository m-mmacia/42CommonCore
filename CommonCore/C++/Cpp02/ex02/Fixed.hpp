/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:02 by mmacia            #+#    #+#             */
/*   Updated: 2024/09/16 14:27:07 by mmacia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _save_float;
    static const int _save_bits = 8;
public:
    Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed (const Fixed &Fixcpy);
    Fixed (const float num);
    Fixed (const int num);
    float toFloat(void) const;
    int toInt(void) const;

    Fixed &operator=(const Fixed& other);

    bool operator>(Fixed fixed)const;
    bool operator<(Fixed fixed)const;
    bool operator>=(Fixed fixed)const;
    bool operator<=(Fixed fixed)const;
    bool operator==(Fixed fixed)const;
    bool operator!=(Fixed fixed)const;

    Fixed operator+(Fixed fixed)const;
    Fixed operator-(Fixed fixed)const;
    Fixed operator*(Fixed fixed)const;
    Fixed operator/(Fixed fixed)const;

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static const Fixed &min(Fixed const &cpy_one, Fixed const &cpy_two);
    static const Fixed &max(Fixed const &cpy_one, Fixed const &cpy_two);
    static Fixed &min(Fixed &x, Fixed &y);
    static Fixed &max(Fixed &x, Fixed &y);

    ~Fixed();
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);


#endif
