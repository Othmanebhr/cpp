#include "../includes/Fixed.hpp"

//constructeur
/*Sert a init*/
Fixed::Fixed() : _rawbits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//constructeur de copie
/* Va copié a la créations d'un objet,
Va servir a evité des copie inutile,
Comme par exemple dans le cas d'un appel de fonction
*/
Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawbits = src.getRawBits();//a revoir
}

//opérateur d'affectation
/* Va servir a copié dans un cas ou l'objet existe deja*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_rawbits = rhs._rawbits;
    }
    return *this;
}

//Destructeur
Fixed::~Fixed()
{
    std::cout << "Destructor is called" << std::endl;
}

//getter
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawbits;
}

//setter
void    Fixed::setRawbits(int const raw)
{
    //Verif si il n'y a pas de messages a envoyé
    _rawbits = raw;
}