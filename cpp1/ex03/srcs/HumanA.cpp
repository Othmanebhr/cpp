#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name), Weapon_(weapon){}

void	HumanA::attack()
{
	std::cout << this->name_ << " attacks with their " << this->Weapon_.get_type() << std::endl;
}