#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public :
	HumanA(std::string name, Weapon& weapon);
	void	attack();

	private :
	std::string	name_;
	Weapon&		Weapon_;

};

#endif