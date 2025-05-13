#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Harl 'level'" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(av[1]);
}