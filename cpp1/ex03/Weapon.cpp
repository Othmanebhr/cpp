#include "Weapon.hpp"

const std::string	Weapon::get_type()
{
	return type_;
}

void	Weapon::set_type(std::string new_value)
{
	this->type_ = new_value;
}