#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
    Fixed();//C
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& src);//C.COPY
    
    ~Fixed();//D
    
    Fixed& operator=(const Fixed& rhs);//Opérateur d'affectation

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++();
    Fixed  operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    private:
    int     _rawbits;
    static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif