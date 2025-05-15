#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;  // Ajout du message
}

Fixed::Fixed(const int value) : _rawbits(value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawbits = value << _bits;
}

Fixed::Fixed(const float value) : _rawbits(value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawbits = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;  // Changement du message
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;  // Correction de l'orthographe
	if (this != &rhs)
	{
		this->_rawbits = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)_rawbits / (1 << _bits);
}

int Fixed::toInt(void) const
{
	return _rawbits >> _bits;
}

int Fixed::getRawBits(void) const
{
	return _rawbits;
}

void	Fixed::setRawBits(int const raw)
{
	_rawbits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

/*Decalage de bits de 8 pour creer un nouvel octect pour le float*/