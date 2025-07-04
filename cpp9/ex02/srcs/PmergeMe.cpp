#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
		if (this != &cpy)
		{
			this->_deque = cpy._deque;
			this->_vector = cpy._vector;
		}
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
	}
	return (*this);
}

bool PmergeMe::parseInput(std::string input)//verif nb > int max?
{
	std::stringstream flux_input(input);
	std::string token;

	while (flux_input >> token)
	{
		for (size_t i = 0; i < token.length(); i++)
		{
			if (!std::isdigit(token[i]))
				return false;
		}
		int nb = std::stoi(token);
		if (nb < 0)
			return false;
		_vector.push_back(nb);
		_deque.push_back(nb);
	}
	return true;
}

bool PmergeMe::getInput(char *str)
{
	std::string input = str;

	if (!this->parseInput(input))
	{
		std::cout << "Error: Bad input." << std::endl;
		return false;
	}
	return true;
}