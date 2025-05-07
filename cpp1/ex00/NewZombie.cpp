#include "Zombie.hpp"

Zombie	*new_zombie(std::string name)
{
	Zombie	*Heap_zombie = new Zombie(name);
	Heap_zombie->announce();
	return Heap_zombie;
}
