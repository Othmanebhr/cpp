#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name_ << "attacks with their " << this->Weapon_.get_type() << std::endl;
}