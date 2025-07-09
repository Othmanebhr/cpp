#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <limits>
#include <unistd.h>
#include <cstdlib>

class Bitcoin
{
	public:
	Bitcoin() {};
	Bitcoin(const Bitcoin& cpy) { *this = cpy; };
	Bitcoin& operator=(const Bitcoin& rhs)
	{
		if (this != &rhs) {
			this->_map = rhs._map;
			this->_data = rhs._data;
			this->_date = rhs._date;
			this->_nb = rhs._nb;
		}
		return *this;
	}
	~Bitcoin() {};

	/*Members function*/
	void parseLine(std::ifstream& input_file, Bitcoin& Data);

	void open_get_input(char *input, char *data);
	bool validateDate();
	float trim_value(std::string& value);

	void searchAndPrintExchange(const std::string& date, float value);

	bool fill_data(std::ifstream& data_file);

	/*Setter, Getter*/
	std::map<std::string, float> getMap() const { return _map; }

	private:
	std::map<std::string, float> _map;
	std::map<std::string, float> _data;
	std::string _date;
	float _nb;
};