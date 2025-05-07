#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << this->name_ << "attacks with their " << this->Weapon_.get_type() << std::endl;
}