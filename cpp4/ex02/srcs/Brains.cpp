#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor has been called." << std::endl;
}

Brain::Brain(const Brain& cpy)
{
	std::cout << "Brain: copy constructor called." << std::endl;
	*this = cpy;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain: Assignation operator called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor has been called." << std::endl;
}

std::string	Brain::getIdea(size_t i)
{
	if (i >= 100)
		return "There is only 100 ideas!";
	return this->_ideas[i];
}

void	Brain::setIdeas(size_t i, std::string idea)
{
	if (i >= 100)
		std::cout << "It can only be 100 ideas!" << std::endl;
	else
	{
		this->_ideas[i] = idea;
		std::cout << "Idea set!" << std::endl;
	}
}