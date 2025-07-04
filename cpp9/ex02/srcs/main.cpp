#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: usage: ./PmergeMe 'nb, nb,...'";
		return 1;
	}
	PmergeMe PmergeMe;
	PmergeMe.GetInput(av[1]);
}