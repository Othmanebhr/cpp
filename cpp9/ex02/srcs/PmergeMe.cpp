#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
	if (this != &cpy)
	{
		this->_deque = cpy._deque;
		this->_vector = cpy._vector;
		this->_vectorTime = cpy._vectorTime;
		this->_dequeTime = cpy._dequeTime;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
		this->_vectorTime = rhs._vectorTime;
		this->_dequeTime = rhs._dequeTime;
	}
	return (*this);
}

/*Sort*/

std::vector<int> PmergeMe::generateJabobsthalsequence(int n)
{
	std::vector<int> JacobSthal;

	if (n == 0)
		return JacobSthal;//a voir si on return autre chose a cause des comportement indefini
	JacobSthal.push_back(1); //pourquoi pas 0
	if (n == 1)
		return JacobSthal;
	JacobSthal.push_back(3);
	while (true)
	{
		int next = JacobSthal[JacobSthal.size() - 1] + 2 * JacobSthal[JacobSthal.size() - 2];
		if (next > n)
			break;
		JacobSthal.push_back(next); // J(n) = J(n - 1) + 2 * J(n - 2)
	}
	return JacobSthal;
}

template <typename T>
void PmergeMe::binaryInsertion(T& container, int value, int end)
{
	int left = 0, right = end;

	while (left < right)
	{
		int mid = left + (right - left) / 2 // (Right + left) / 2 Potentiel overflow
		if (container[mid] < left)
			left = mid + 1;
		else
			right = mid;
	}
	container.insert(container.begin() + left, value);
}
/*
mid = left + (right - left) / 2
    = left + right/2 - left/2
    = left/2 + right/2 + left/2
    = (left + right) / 2
*/

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



void PmergeMe::mergeInsertSortVector(std::vector<int>& vector, int left, int right)
{
	if (left >= right)
		return ;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deque, int left, int right)
{

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