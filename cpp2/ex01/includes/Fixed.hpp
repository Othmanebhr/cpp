#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
    Fixed();
    Fixed(const int value);//constructeur
    Fixed(const float value);
    Fixed(const Fixed& src);//constructeur de copie

    Fixed& operator=(const Fixed& rhs);//opérateur d'affectation

    ~Fixed();//destructeur

    float toFloat() const;
    int   toInt() const;
    int    getRawBits() const;
    void    setRawBits(int const raw);

    private:
    int _rawbits;
    static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif