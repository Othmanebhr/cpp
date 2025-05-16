#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat: Default Constructor called." << std::endl;
	_type = "Cat";
	this->_Brain = new Brain();
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
	std::cout << "Cat: copy constructor called." << std::endl;
	this->_type = cpy._type;
	this->_Brain = new Brain(*cpy._Brain);
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: Assignation operator called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		if (this->_Brain)
			delete _Brain;
		this->_Brain = new Brain(*rhs._Brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called." << std::endl;
	delete this->_Brain;
}

void	Cat::makeSound() const
{
	std::cout << "Cat: MIAOU MIAOU." << std::endl;
}

Brain	*Cat::getBrain() const
{
	return _Brain;
}