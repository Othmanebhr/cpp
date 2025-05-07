#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
	const std::string	get_type();
	void				set_type(std::string new_value);

	private:
	std::string type_;
};

#endif