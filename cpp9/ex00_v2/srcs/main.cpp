#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **av)
{

	/* PARSE FICHIER .CSV*/
	if (argc != 3)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	Bitcoin btc;
	btc.open_get_input(av[1], av[2]);
	return 0;
}