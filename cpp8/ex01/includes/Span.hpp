#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

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