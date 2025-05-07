#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 1)
	{
		std::cout << "A Horde should have at leat 2 zombie!" << std::endl;
		return NULL;
	}
	Zombie	*Horde = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		Horde[i].set_name(name);
		Horde[i].set_idx(i + 1);
		Horde[i].announce();
	}
	return Horde;
}