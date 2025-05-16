#include "../includes/Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal: Default constructor has been called." << std::endl;
}

Animal::Animal(const Animal& cpy)
{
	std::cout << "Animal: copy constructor called." << std::endl;
	*this = cpy;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal: Assignation operator called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor has been called." << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}