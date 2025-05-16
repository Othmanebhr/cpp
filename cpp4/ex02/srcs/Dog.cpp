#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: Default Constructor called." << std::endl;
	_type = "Dog";
	this->_Brain = new Brain();
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
	std::cout << "Dog: copy constructor called." << std::endl;
	this->_type = cpy._type;
	this->_Brain = new Brain(*cpy._Brain);
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: Assignation operator called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		if (this->_Brain)
			delete _Brain;
		this->_Brain = new Brain(*rhs._Brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called." << std::endl;
	delete this->_Brain;
}

void	Dog::makeSound() const
{
	std::cout << "Dog: WAf WAF." << std::endl;
}

Brain	*Dog::getBrain() const
{
	return _Brain;
}