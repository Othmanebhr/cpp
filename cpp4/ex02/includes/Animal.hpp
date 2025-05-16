#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <cctype>
#include <iostream>

class Animal
{
	public:
	Animal();
	Animal(const Animal& cpy);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	virtual void	makeSound() const = 0;

	std::string	getType() const;
	protected:
	std::string	_type;

};

#endif