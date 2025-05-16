#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal: Default constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	std::cout << "Animal: copy constructor called." << std::endl;
	*this = cpy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor has been called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Je suis un chat un peu con, en plus je parle au mauvais endroit." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}