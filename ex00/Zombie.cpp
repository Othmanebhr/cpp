#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name){}


Zombie::~Zombie()
{
	std::cout << this->name_ << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name_ << " : BraiiiiiiinnnzzzZ.." << std::endl;
}

// int main()
// {
// 	Zombie bob("bob");
// 	bob.announce();
// 	return 0;
// }
