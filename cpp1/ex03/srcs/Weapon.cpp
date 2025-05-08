#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

const std::string	Weapon::get_type()
{
	return type_;
}

void	Weapon::setType(std::string new_value)
{
	this->type_ = new_value;
}