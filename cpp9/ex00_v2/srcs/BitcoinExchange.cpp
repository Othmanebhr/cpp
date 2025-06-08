#include "../includes/BitcoinExchange.hpp"
#define ERR_BI "Error: Bad input ==> "

void Bitcoin::trim_date()
{
	const char *d = _date.c_str();

	//isalpha (+ajout de check si '-' > 2)

	if (d[4] != '-' || d[7] != '-')
		std::cerr << ERR_BI << _date << std::endl;
	std::string tmp = _date.substr(0, '-');
	d = tmp.c_str();
	if (std::atoi(d) > 2022 || std::atoi(d) < 2009)
		std::cerr << ERR_BI << _date << std::endl;
	size_t minus_pos = _date.find("-");
	size_t second_minus_pos = _date.find("-", minus_pos + 1);
	tmp = _date.substr(minus_pos + 1, second_minus_pos - 1);
	d = tmp.c_str();
	if (std::atoi(d) > 12 || std::atoi(d) < 1)
		std::cerr << ERR_BI << _date << std::endl;
	tmp = _date.substr(second_minus_pos + 1, ' '); // Ne pas oublier l'espace a la fin
	d = tmp.c_str();
	if (std::atoi(d) > 31 || std::atoi(d) < 1)
		std::cerr << ERR_BI << _date << std::endl;
	_map[_date] = _nb;
	//Appel de l'algo ici pour chaque element
}

float Bitcoin::trim_value(std::string value)
{
	const char *val = value.c_str();

	if (val[0] != ' ')
		return false;
	size_t start = 1;
	if (val[start] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	bool hasDecimal = false;
	for (size_t i = start; i < value.length() - 1; i++)
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
	float _nb = std::atof(val + start);
	if (_nb > 1000)
	{
		std::cerr << "Eroor: nb too big." << std::endl;
		return -1;
	}
	return _nb;
}

bool Bitcoin::parseLine(std::ifstream input_file, Bitcoin Data)
{
	std::string line;
	std::getline(input_file, line);
	if (line.empty())
		std::cout << "Empty file." << std::endl;
	if (line != "date | value")
	{
		std::cerr << "Bad input" << std::endl;
		return false;
	}
	while (std::getline(input_file, line))
	{
		size_t pipe_pos = line.find("|");
		if (pipe_pos == std::string::npos)
			std::cerr << ERR_BI << line << std::endl;
		_date = line.substr(0, pipe_pos); //a voir si cela prends le pipe
		std::string value = line.substr(pipe_pos + 1);
		_nb = Data.trim_value(value);
		if (_nb != -1)
			Data.trim_date();
	}
	return true;
}

bool Bitcoin::open_get_input(char *data)
{
	std::ifstream input_file;
	Bitcoin Data;

	input_file.open(data);
	if (!input_file.is_open())
	{
		std::cerr << "Error: cannot open file." << std::endl;
		return false;
	}
	//OUVERTURE DU FILE DATA ET ANALYSE DANS TRIM__DATE
	Data.parseLine(input_file, Data);
	input_file.close();
	return true;
}
