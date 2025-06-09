#include "../includes/BitcoinExchange.hpp"
#define ERR_BI "Error: Bad input ==> "
#define ERR_DATA "Error: Bad data file."

void Bitcoin::searchAndPrintExchange(const std::string& date, float value)
{
	std::map<std::string, float>::iterator it = _data.upper_bound(date);
	if (it == _data.begin() && it->first != date)
	{
		std::cerr << "Error: no data available for date " << date << std::endl;
		return;
	}
	if (it == _data.end() || it->first != date)
		--it;
	float exchange_rate = it->second;
	float result = value * exchange_rate;

	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool Bitcoin::validateDate()
{
	const char *d = _date.c_str();

	// Vérifier le format général de la date (YYYY-MM-DD)
	if (d[4] != '-' || d[7] != '-') {
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}

	// Vérifier l'année (entre 2009 et 2022)
	std::string tmp = _date.substr(0, 4);
	d = tmp.c_str();
	if (std::atoi(d) > 2022 || std::atoi(d) < 2009) {
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}

	// Vérifier le mois (entre 1 et 12)
	size_t minus_pos = _date.find("-");
	size_t second_minus_pos = _date.find("-", minus_pos + 1);
	tmp = _date.substr(minus_pos + 1, second_minus_pos - minus_pos - 1);
	d = tmp.c_str();
	if (std::atoi(d) > 12 || std::atoi(d) < 1) {
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}

	// Vérifier le jour (entre 1 et 31)
	tmp = _date.substr(second_minus_pos + 1);
	d = tmp.c_str();
	if (std::atoi(d) > 31 || std::atoi(d) < 1) {
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}
	_map[_date] = _nb;
	return true;
}

float Bitcoin::trim_value(std::string& value)
{
	const char *val = value.c_str();

	if (val[0] != ' ')
		return -1; // This should return -1 or some other error indicator
	size_t start = 1;
	if (val[start] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	bool hasDecimal = false;
	for (size_t i = start; i < value.length(); i++) // Fix: removed -1
	{
		if (std::isdigit(val[i]))
			continue;
		else if (val[i] == '.' && !hasDecimal && i != start)
			hasDecimal = true;
		else
		{
			std::cerr << "Error: not a number." << std::endl;
			return -1;
		}
	}
	float nb = std::atof(val + start); // Change _nb to local variable
	if (nb > 1000)
	{
		std::cerr << "Error: nb too big." << std::endl; // Fix typo in "Error"
		return -1;
	}
	return nb;
}

void Bitcoin::parseLine(std::ifstream& input_file, Bitcoin& input)
{
	std::string line;
	std::getline(input_file, line);
	if (line.empty())
	{
		std::cout << "Empty file." << std::endl;
		return ;
	}
	if (line != "date | value")
	{
		std::cerr << "Bad input" << std::endl;
		return ;
	}
	while (std::getline(input_file, line))
	{
		size_t pipe_pos = line.find("|");
		if (pipe_pos == std::string::npos)
		{
			std::cerr << ERR_BI << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe_pos);
		std::string value_str = line.substr(pipe_pos + 1);
		_date = date;
		float value = input.trim_value(value_str);
		if (value == -1)
			continue;
		if (!validateDate())
			continue;
		searchAndPrintExchange(date, value);
		_map[date] = value;
	}
	// return true;
}

bool Bitcoin::fill_data(std::ifstream& data_file) // Change to reference
{
	std::string line;

	std::getline(data_file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << ERR_DATA << std::endl;
		return false;
	}
	while (std::getline(data_file, line))
	{
		size_t com_pos = line.find(",");
		if (com_pos == std::string::npos)
		{
			std::cerr << ERR_DATA << std::endl;
			return false;
		}
		std::string before_com = line.substr(0, com_pos);
		std::string after_com = line.substr(com_pos + 1);
		try
		{
			float nb = std::atof(after_com.c_str());
			_data[before_com] = nb;
		}
		catch (std::exception &e)
		{
			std::cerr << ERR_DATA << " Invalid format."<< std::endl;
			return false;
		}
	}
	return true;
}

void Bitcoin::open_get_input(char *data_file_name, char *input_file_name)
{
	std::ifstream input_file;
	std::ifstream data_file;

	input_file.open(input_file_name);
	if (!input_file.is_open())
	{
		std::cerr << "Error: cannot open input_file." << std::endl;
		return ;
	}
	data_file.open(data_file_name);
	if (!data_file.is_open())
	{
		std::cerr << "Error: cannot open data_file" << std::endl;
		input_file.close();
		return ;
	}
	if(!fill_data(data_file))
	{
		input_file.close();
		data_file.close();
		return ;
	}
	parseLine(input_file, *this);
	input_file.close();
	data_file.close();
	return ;
}