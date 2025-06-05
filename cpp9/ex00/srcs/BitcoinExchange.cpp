#include "../includes/BitcoinExchange.hpp"

void Bitcoin::trim_date(std::string date)
{
	const char *d = date.c_str();

	//isalpha (+ajout de check si '-' > 2)

	if (d[4] != '-' || d[7] != '-')
		throw ErrorFile();
	std::string tmp = date.substr(0, '-');
	d = tmp.c_str();
	if (std::atoi(d) > 2022 || std::atoi(d) < 2009)
	{
		std::cerr << date << "==>" << std::endl;
		throw TooBig();
	}
	size_t minus_pos = date.find("-");
	size_t second_minus_pos = date.find("-", minus_pos + 1);
	tmp = date.substr(minus_pos + 1, second_minus_pos - 1);
	d = tmp.c_str();
	if (std::atoi(d) > 12 || std::atoi(d) < 1)
	{
		std::cerr << date << "==>" << std::endl; // Affchage a revoir (dans le mauvais ordre)
		throw TooBig();
	}
	tmp = date.substr(second_minus_pos + 1, ' '); // Ne pas oublier l'espace a la fin
	d = tmp.c_str();
	if (std::atoi(d) > 31 || std::atoi(d) < 1)
	{
		std::cerr << date << "==>" << std::endl;
		throw TooBig();
	}
}

float Bitcoin::trim_value(std::string value)
{
	const char *val = value.c_str();

	if (val[0] != ' ')
		return false;
	size_t start = 1;
	if (val[start] == '-')
		throw NotPositive();
	bool hasDecimal = false;
	for (size_t i = start; i < value.length() - 1; i++)
	{
		if (std::isdigit(val[i]))
			continue;
		else if (val[i] == '.' && !hasDecimal && i != start)
			hasDecimal = true;
		else
			throw NotNumber();
	}
	float nb = std::atof(val + start);
	if (nb > 1000)
		throw TooBig();
	return nb;
}

bool Bitcoin::parseLine(std::ifstream input_file)
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
		try
		{
			size_t pipe_pos = line.find("|");
			if (pipe_pos == std::string::npos)
				throw ErrorFile();
			std::string date = line.substr(0, pipe_pos); //a voir si cela prends le pipe
			std::string value = line.substr(pipe_pos + 1);
			trim_date(date);
			float nb = trim_value(value);
			_map[date] = nb;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	//parse ok, envoyer date et nb dans la map
	return true;
}

bool Bitcoin::open_get_input(char *data)
{
	std::ifstream input_file;
	Bitcoin Data;

	input_file.open(data);
	try
	{
		if (!input_file.is_open())
			throw ErrorFile();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	Data.parseLine(input_file);
	input_file.close();
	return true;
}
