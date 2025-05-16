#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
	Brain();
	Brain(const Brain& cpy);
	Brain&	operator=(const Brain& rhs);
	~Brain();

	void		setIdeas(size_t i, std::string idea);
	std::string	getIdea(size_t i);

	private:
	std::string	_ideas[100];
};

#endif