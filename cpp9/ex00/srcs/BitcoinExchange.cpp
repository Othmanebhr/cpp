#include "../includes/BitcoinExchange.hpp"

bool Bitcoin::parseLine(std::ifstream input_file)
{
	std::string line;
	//il faut skip le header
	while (std::getline(input_file, line))
	{
		try
		{
			size_t pipe_pos = line.find("|");
			if (pipe_pos != std::string::npos)
	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	if (line.empty())
		std::cout << "Empty file." << std::endl;
}

bool Bitcoin::open_get_input(char *data)
{
	std::ifstream input_file;

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
	parseFile(input_file);
	input_file.close();
	return true;
}
