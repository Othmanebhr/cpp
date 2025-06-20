#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: usage: ./RPN 'calcul'." << std::endl;
		return 1;
	}
	std::string arg = av[1];
	RPN calcul(arg);
	if (!calcul.calculate())
		return 1;
	return 0;
}