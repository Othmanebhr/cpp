#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();

    int     getRawBits() const;
    void    setRawbits(int const raw);

    private:
    int _rawbits;
    static const int _bits = 8;
};

#endif