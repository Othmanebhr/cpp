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
	JacobSthal.push_back(1);
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

std::deque<int> PmergeMe::generateJabobsthalsequenceD(int n)
{
	std::deque<int> JacobSthal;

	if (n == 0)
		return JacobSthal;//a voir si on return autre chose a cause des comportement indefini
	JacobSthal.push_back(1);
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

void PmergeMe::binaryInsertion(std::vector<int>& container, int value, int end)
{
	int left = 0, right = end;

	while (left < right)
	{
		int mid = left + (right - left) / 2; // (Right + left) / 2 Potentiel overflow
		if (container[mid] < value)
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

void PmergeMe::binaryInsertionD(std::deque<int>& container, int value, int end)
{
	int left = 0, right = end;

	while (left < right)
	{
		int mid = left + (right - left) / 2; // (Right + left) / 2 Potentiel overflow
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	container.insert(container.begin() + left, value);
}

void PmergeMe::sortVector()
{
	if (_vector.empty())
		return ;
	clock_t start = clock();
	fordJohnsonSortVector(_vector);
	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return ;

	std::vector<std::pair<int, int> > pairs;
	int alone = -1;
	bool hasAlone = false;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (i + 1 < vec.size())
		{
			if (vec[i] > vec[i + 1])
				pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
			else
				pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
		else
		{
			alone = vec[i];
			hasAlone = true;
		}
	}

	std::vector<int> bigChain;
	std::vector<int> smallChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		bigChain.push_back(pairs[i].first);
		smallChain.push_back(pairs[i].second);
	}

	if (bigChain.size() > 1)
		fordJohnsonSortVector(bigChain);

	vec.clear();

	if (!smallChain.empty())
	{
		vec.push_back(smallChain[0]);
		for (size_t i = 0; i < bigChain.size(); i++)
			vec.push_back(bigChain[i]);
		std::vector<int> JacobSthal = generateJabobsthalsequence(smallChain.size());
		std::vector<bool> inserted(smallChain.size(), false);//constructeur std::vector<type> vec(taille, valeur par defaults)
		inserted[0] = true;
		for (size_t j = 0; j < JacobSthal.size(); j++)
		{
			size_t jsValue = JacobSthal[j];
			if (jsValue <= smallChain.size() && !inserted[jsValue - 1])
			{
				binaryInsertion(vec, smallChain[jsValue - 1], vec.size());
				inserted[jsValue - 1] = true;
			}
		}
		for (size_t i = 1; i < smallChain.size(); i++)
		{
			if (!inserted[i])
				binaryInsertion(vec, smallChain[i], vec.size());
		}
	}
	else if (smallChain.empty() && !bigChain.empty())
		vec = bigChain;
	if (hasAlone)
		binaryInsertion(vec, alone, vec.size());
}

void PmergeMe::sortDeque()
{
	if (_deque.empty())
		return ;
	clock_t start = clock();
	fordJohnsonSortDeque(_deque);
	clock_t end = clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deque)
{
	if (deque.size() <= 1)
		return ;

	std::deque<std::pair<int, int> > pairs;
	int alone = -1;
	bool hasAlone = false;
	for (size_t i = 0; i < deque.size(); i += 2)
	{
		if (i + 1 < deque.size())
		{
			if (deque[i] > deque[i + 1])
				pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
			else
				pairs.push_back(std::make_pair(deque[i + 1], deque[i]));

		}
		else
		{
			alone = deque[i];
			hasAlone = true;
		}
	}

	std::deque<int> BigChain;
	std::deque<int> SmallChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		BigChain.push_back(pairs[i].first);
		SmallChain.push_back(pairs[i].second);
	}

	deque.clear();

	if (BigChain.size() > 1)
		fordJohnsonSortDeque(BigChain);
	if (!SmallChain.empty())
	{
		deque.push_back(SmallChain[0]);
		for (size_t i = 0; i < BigChain.size(); i++)
			deque.push_back(BigChain[i]);
		std::deque<int> Jabobsthal = generateJabobsthalsequenceD(SmallChain.size());
		std::deque<bool> inserted(SmallChain.size(), false);
		inserted[0] = true;
		for (size_t j = 0; j < Jabobsthal.size(); j++)
		{
			size_t jsValue = Jabobsthal[j];
			if (jsValue <= SmallChain.size() && !inserted[jsValue - 1])
			{
				binaryInsertionD(deque, SmallChain[jsValue - 1], deque.size());
				inserted[jsValue - 1] = true;
			}
		}
		for (size_t i = 1; i < SmallChain.size(); i++)
		{
			if (!inserted[i])
				binaryInsertionD(deque, SmallChain[i], deque.size());
		}
	}
	else if (SmallChain.empty() && !BigChain.empty())
		deque = BigChain;
	if (hasAlone)
		binaryInsertionD(deque, alone, deque.size());
}

/*Print*/
void PmergeMe::printContainer(bool before)
{
	std::cout << (before ? "Before" : "After") << ": ";
	for (size_t i = 0; i < _vector.size() && i < 5; i++)
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
			if (i == 0 && token[i] == '+')
				continue;
			if (!std::isdigit(token[i]))
				return false;
		}
		try
		{
			long long nb;
			std::stringstream ss(token);
			ss >> nb;
			if (ss.fail() || !ss.eof())
				return false;
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

bool PmergeMe::getInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!this->parseInput(av[i]))
		{
			std::cout << "Error: Bad input." << std::endl;
			return false;
		}
	}
	return true;
}

/*ALL*/
void PmergeMe::run()
{
	printContainer(true);
	sortVector();
	sortDeque();
	printContainer(false);
	displayResults();
}