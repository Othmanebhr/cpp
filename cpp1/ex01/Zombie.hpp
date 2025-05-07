#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
	public:
	Zombie();
	~Zombie();
	void	set_name(std::string name);
	void	set_idx(int n);
	void	announce();

	private:
	std::string	name_;
	size_t		idx_;
};

Zombie* zombieHorde( int N, std::string name );

#endif