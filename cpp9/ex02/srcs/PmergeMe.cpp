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

/*Sort*/
void PmergeMe::sortVector()
{
	if (_vector.empty())
		return ;
	clock_t start = clock();
	mergeInsertSortVector(_vector, 0, _vector.size() - 1);
	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::sortDeque()
{
	if (_deque.empty())
		return ;
	clock_t start = clock();
	mergeInsertSortDeque(_deque, 0, _deque.size() - 1);
	clock_t end = clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

/*Print*/
void PmergeMe::printContainer(const std::string& name, bool before)
{
	std::cout << (before ? "Before" : "After") << ": ";
	for (size_t i = 0; _vector.size() && i < 5; i++)
		std::cout << _vector[i] << " ";
	if (_vector.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::displayResults()
{
	std::cout << "Time to process a range of " << _vector.size()
	<< " elements with std::vector: " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
	<< " elements with std::deque: " << _dequeTime << " us" << std::endl;
}

/*Parsing*/
bool PmergeMe::parseInput(std::string input)
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
		try
		{
			long long nb = std::stoll(token);
			if (nb < 0 || nb > INT_MAX)
				return false;
			_vector.push_back(nb);
			_deque.push_back(nb);
		}
		catch (std::exception& e)
		{
			return false;
		}
	}
	return true;
}

/*ALL*/
bool PmergeMe::getInput(int ac, char **av)
{
	for (size_t i = 0; i < ac; i++)
	{
		if (!this->parseInput(av[i]))
		{
			std::cout << "Error: Bad input." << std::endl;
			return false;
		}
	}
	return true;
}