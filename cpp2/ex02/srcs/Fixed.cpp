#include "../includes/Fixed.hpp"

//Constructors/destructors
Fixed::Fixed() : _rawbits(0){}

Fixed::Fixed(const int value) : _rawbits(value << _bits){}

Fixed::Fixed(const float value) : _rawbits(roundf(value * (1 << _bits))){}

Fixed::Fixed(const Fixed& src){ *this = src; }

Fixed::~Fixed(){}

//operators
/*(affectation)*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        _rawbits = rhs.getRawBits();
    return *this;
}

bool    Fixed::operator>(const Fixed& rhs) const { return _rawbits > rhs.getRawBits(); }
bool    Fixed::operator<(const Fixed& rhs) const { return _rawbits < rhs.getRawBits(); }

bool    Fixed::operator>=(const Fixed& rhs) const { return _rawbits >= rhs.getRawBits(); }
bool    Fixed::operator<=(const Fixed& rhs) const { return _rawbits <= rhs.getRawBits(); }

bool    Fixed::operator==(const Fixed& rhs) const { return _rawbits == rhs.getRawBits(); }
bool    Fixed::operator!=(const Fixed& rhs) const { return _rawbits != rhs.getRawBits(); }


Fixed   Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(_rawbits + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(_rawbits - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed r;
    r.setRawBits((_rawbits * rhs.getRawBits()) >> _bits);
    return r;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed r;
    r.setRawBits(_rawbits / rhs.getRawBits());
    return r;
}

//pré-incrementation/decrementation
Fixed& Fixed::operator++()
{
    ++_rawbits;
    return *this;
}

Fixed& Fixed::operator--()
{
    --_rawbits;
    return *this;
}

//post-incrementation/decrementation
Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_rawbits;
    return temp;
}

Fixed   Fixed::operator--(int)
{
    Fixed temp(*this);
    --_rawbits;
    return (temp);
}

//fonction simple
float Fixed::toFloat(void) const
{
    return (float)_rawbits / (1 << _bits);
}

int Fixed::toInt(void) const
{
    return _rawbits >> _bits;
}

//geter/seter
void    Fixed::setRawBits(int const raw) { _rawbits = raw; }
int     Fixed::getRawBits() const { return _rawbits; }

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if ( a < b )
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}