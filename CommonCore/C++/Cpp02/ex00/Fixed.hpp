#ifndef FIXED_HPPP
# define FIXED_HPPP

# include <iostream>

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
    Fixed& operator=(const Fixed& other);
    ~Fixed();
};


#endif