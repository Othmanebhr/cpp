#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << "Zombie : " << idx_ << "destroyed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	name_ = name;
}

void	Zombie::announce()
{
	std::cout << name_ << " Number:" << idx_ << " : BraiiiiiiinnnzzzZ.." << std::endl;
}

void	Zombie::set_idx(int n)
{
	idx_ = n;
}