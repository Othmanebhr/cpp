#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <limits>

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
	bool parseLine(std::ifstream input_file, Bitcoin Data);
	bool open_get_input(char *data);
	void trim_date();
	float trim_value(std::string value);

	/*Setter, Getter*/
	std::map<std::string, float> getMap();

	private:
	std::map<std::string, float> _map;
	std::string _date;
	float _nb;
};