#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

class Span
{
	public:
	Span(int max);
	Span(const Span& cpy);
	Span& operator=(const Span& rhs);
	~Span();

	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();

	void addRange(size_t nb);

	template<typename Iterator>
	void addRange2(Iterator beg, Iterator end);

	class TooManyElem : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class NotEnoughElem : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	private:
	std::vector<int> _vec;

};

template<typename Iterator>
void Span::addRange2(Iterator beg, Iterator end)
{
	size_t dist = std::distance(beg, end);
	if (dist > _vec.capacity() - _vec.size())
		throw TooManyElem();

	_vec.insert(_vec.end(), beg, end);
}