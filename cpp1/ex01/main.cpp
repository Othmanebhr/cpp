#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "1 args needed, ./Zombie 'Name_of_the_horde' 'Nb_of_Zombies' " << std::endl;
		return 1;
	}
	int nb = atoi(av[2]);
	if (nb < 0)
	{
		std::cout << "Please set a decent amount of zombies!" << std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(nb, av[1]);
	delete[] horde;
	return 0;
}