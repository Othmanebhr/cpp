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
	bool parseLine(std::ifstream input_file);
	bool open_get_input(char *data);
	static void trim_date(std::string date);
	static float trim_value(std::string value);

	/*Setter, Getter*/
	std::map<std::string, float> getMap();

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

	class TooBig : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return "Eroor: nb too big.";
		}
	};

	private:
	std::map<std::string, float> _map;
};