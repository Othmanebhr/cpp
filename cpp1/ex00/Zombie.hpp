#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		void	announce();
		Zombie	*new_zombie(std::string name);

	private:
		std::string name;
};

#endif