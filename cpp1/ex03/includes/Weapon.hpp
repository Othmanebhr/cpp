#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
	Weapon(std::string type);
	const std::string&	get_type();
	void				setType(std::string new_value);

	private:
	std::string type_;
};

#endif