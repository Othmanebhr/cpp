#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(const Dog& cpy);
	Dog& operator=(const Dog& rhs);
	~Dog();

	void	makeSound() const /*override*/;
	Brain	*getBrain() const;

	private:
	Brain	*_Brain;

};

#endif