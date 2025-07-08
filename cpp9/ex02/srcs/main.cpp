#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: " << av[0] << " [positive integers]" << std::endl;
		return 1;
	}
	PmergeMe sorter;
	if (!sorter.getInput(ac, av))
		return 1;
	sorter.run();
	return 0;
}