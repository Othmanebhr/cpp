#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
	Array();
	Array(unsigned int n);
	Array(const Array& cpy);
	Array& operator=(const Array& rhs);
	~Array();

	T& operator[](unsigned int idx);
	const T& operator[](unsigned int idx) const;

	unsigned int size() const;

	class OutOfArray : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class InvalidArgs : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	private:
	T	*_array;
	unsigned int _size;

};

#include "../srcs/Array.tpp"

#endif