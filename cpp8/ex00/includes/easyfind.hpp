#pragma once

#include <iostream>
#include <exception>
#include <algorithm>//find
#include <vector>

class NotFind : public std::exception
{
	public:
	virtual const char *what() const throw();
};

const char *NotFind::what() const throw()
{
	return "Data not found.";
}

template<typename T>

typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw NotFind();
	return it;
}