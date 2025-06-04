#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>

class Bitcoin
{
	public:
	/*Canonical form*/
	Bitcoin() {};
	Bitcoin(const Bitcoin& cpy) { *this = cpy; };
	Bitcoin& operator=(const Bitcoin& rhs)//// MAP A AJOUTE
	{
		if (this != &rhs) {}
		return *this;
	}
	~Bitcoin() {};

	/*Members function*/
	static bool parseLine(std::ifstream input_file);
	bool open_get_input(char *data);

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

	class ErrorFile : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error: Bad input";
			}
	};

	private:
	std::map<std::string, float> _map;
};