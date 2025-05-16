#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat: Default Constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy) { std::cout << "WrongCat: copy constructor called." << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat: Assignation operator called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: MIAOU MIAOU." << std::endl;
}