#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy) { std::cout << "Cat: copy constructor called." << std::endl; }

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: Assignation operator called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat: MIAOU MIAOU." << std::endl;
}