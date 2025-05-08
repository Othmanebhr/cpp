#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public :
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	attack();

	private :
	Weapon*		weapon_;
	std::string	name_;

};

#endif