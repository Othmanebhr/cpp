#include "../includes/Span.hpp"

Span::Span(int max)
{
	this->_vec.reserve(max);
}

Span::Span(const Span& cpy)
{
	*this = cpy;
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < rhs._vec.size(); i++)
			this->_vec[i] = rhs._vec[i];
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (this->_vec.capacity() > 0)
		this->_vec.push_back(nb);
	else 
		throw TooManyElem();
}

int Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw NotEnoughElem();
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw NotEnoughElem();
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::TooManyElem::what() const throw()
{
	return "Too many elements.";
}

const char *Span::NotEnoughElem::what() const throw()
{
	return "Not enough elements.";
}