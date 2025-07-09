#include "../includes/BitcoinExchange.hpp"
#define ERR_BI "Error: Bad input ==> "
#define ERR_DATA "Error: Bad data file."
#define ERR_FILE "Error: Bad format: '.csv' is required."

void Bitcoin::searchAndPrintExchange(const std::string& date, float value)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
	{
		float exchange_rate = it->second;
		float result = value * exchange_rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
		return;
	}
	if (it == _data.begin())
	{
		std::cerr << "Error: no data available for date " << date << std::endl;
		return;
	}
	--it;
	float exchange_rate = it->second;
	float result = value * exchange_rate;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool Bitcoin::validateDate()
{
	const char *d = _date.c_str();

	//YYYY-MM-DD
	if (d[4] != '-' || d[7] != '-')
	{
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}
	//année (entre 2009 et 2022)
	std::string tmp = _date.substr(0, 4);
	d = tmp.c_str();
	if (std::atoi(d) > 2022 || std::atoi(d) < 2009)
	{
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}
	//mois (entre 1 et 12)
	size_t minus_pos = _date.find("-");
	size_t second_minus_pos = _date.find("-", minus_pos + 1);
	tmp = _date.substr(minus_pos + 1, second_minus_pos - minus_pos - 1);
	d = tmp.c_str();
	if (std::atoi(d) > 12 || std::atoi(d) < 1)
	{
		std::cerr << ERR_BI << _date << std::endl;
		return false;
	}
	// jour (entre 1 et 31)
	tmp = _date.substr(second_minus_pos + 1);
	d = tmp.c_str();
	if (std::atoi(d) > 31 || std::atoi(d) < 1)
	{
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
		return -1;
	size_t start = 1;
	if (val[start] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	bool hasDecimal = false;
	for (size_t i = start; i < value.length(); i++)
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
	float nb = std::atof(val + start);
	if (nb > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}
	return nb;
}

void Bitcoin::parseLine(std::ifstream& input_file, Bitcoin& input)
{
	std::string line;
	if (input_file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Empty file." << std::endl;
		return ;
	}
	std::getline(input_file, line);
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

static bool isValidNb(const std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	bool hasDecimal = false;
	for (; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			if ((hasDecimal == true && str[i] == '.') || str[i] != '.')
				return false;
		}
		if (str[i] == '.')
			hasDecimal = true;
	}
	return true;
}

static bool isValidDate(const std::string& date)
{
	const char *d = date.c_str();

	if (date.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(d[i]))
			return false;
	}
	//YYYY-MM-DD
	if (d[4] != '-' || d[7] != '-')
		return false;
	//année (entre 2009 et 2022)
	std::string tmp = date.substr(0, 4);
	d = tmp.c_str();
	if (std::atoi(d) > 2022 || std::atoi(d) < 2009)
		return false;
	//mois (entre 1 et 12)
	size_t minus_pos = date.find("-");
	size_t second_minus_pos = date.find("-", minus_pos + 1);
	tmp = date.substr(minus_pos + 1, second_minus_pos - minus_pos - 1);
	d = tmp.c_str();
	if (std::atoi(d) > 12 || std::atoi(d) < 1)
		return false;
	// jour (entre 1 et 31)
	tmp = date.substr(second_minus_pos + 1);
	d = tmp.c_str();
	if (std::atoi(d) > 31 || std::atoi(d) < 1)
		return false;
	return true;
}

bool Bitcoin::fill_data(std::ifstream& data_file)
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
		if (!isValidNb(after_com) || !isValidDate(before_com))
		{
			std::cerr << ERR_DATA << " Invalid format."<< std::endl;
			return false;
		}
		float nb = std::atof(after_com.c_str());
		_data[before_com] = nb;
	}
	return true;
}

static bool check_file_name(char *data_file_name)
{
	if (!data_file_name)
	{
		std::cerr << ERR_FILE << std::endl;
		return false;
	}
	std::string tmp = data_file_name;
	size_t pos = tmp.find(".");
	if (pos == std::string::npos)
	{
		std::cerr << ERR_FILE << std::endl;
		return false;
	}
	tmp = tmp.substr(pos);
	if (tmp != ".csv")
	{
		std::cerr << ERR_FILE << std::endl;
		return false;
	}
	return true;
}

void Bitcoin::open_get_input(char *data_file_name, char *input_file_name)
{
	if (!check_file_name(data_file_name))
		return;
	std::ifstream input_file;
	input_file.open(input_file_name);
	if (!input_file.is_open())
	{
		std::cerr << "Error: cannot open input_file." << std::endl;
		return ;
	}
	std::ifstream data_file;
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