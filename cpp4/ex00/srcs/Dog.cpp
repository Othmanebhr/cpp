#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
	std::cout << "Dog: copy constructor called." << std::endl;
	*this = cpy;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: Assignation operator called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog: WAf WAF." << std::endl;
}