#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
	weapon_ = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	weapon_ = &weapon;
}

void	HumanB::attack()
{
	if (weapon_)
		std::cout << this->name_ << " attacks with their " << this->weapon_->get_type() << std::endl;
	else
		std::cout << name_ << "attck with his bare hands" << std::endl;
}