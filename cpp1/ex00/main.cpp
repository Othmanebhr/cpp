#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Please choose 2 args: 1st = Stack_Zombie, 2nd = Heap_zombie" << std::endl;
		return 1;
	}

	std::cout << " ------------" << std::endl;
	std::cout << "|" << "Stack_zombie :" << std::endl;
	std::cout << " ------------" << std::endl;
	randomChump(av[1]);

	std::cout << std::endl;

	std::cout << " -----------" << std::endl;
	std::cout << "|" << "heap_zombie :" << std::endl;
	std::cout << " -----------" << std::endl;
	Zombie *heap_zombie = new_zombie(av[2]);
	delete heap_zombie;
	return 0;
}