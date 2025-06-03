#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bitcoin
{
	public:
	/*Canonical form*/
	Bitcoin() {};
	Bitcoin(const Bitcoin& cpy) { *this = cpy; };
	Bitcoin& operator=(const Bitcoin& rhs)
	{
		if (this != &rhs)
		{
			this->_line = rhs._line; 
		}
		return *this;
	}
	~Bitcoin() {};

	/*Members function*/
	bool parseLine();

	/*Exception*/
	class NotPositive : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error: not a positive number";
			}
	};

	class NotNumber : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error: not a number";
			}
	};

	private:
	std::string _line;
	bool		_isValid;
};