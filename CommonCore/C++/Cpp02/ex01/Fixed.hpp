/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:00 by mmacia            #+#    #+#             */
/*   Updated: 2024/09/16 14:26:06 by mmacia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPPP
# define FIXED_HPPP

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

    float toFloat(void) const;
    int toInt(void) const;

    Fixed (const Fixed &Fixcpy);
    Fixed (const float num);
    Fixed (const int num);

    Fixed& operator=(const Fixed& other);

    ~Fixed();
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);


#endif
