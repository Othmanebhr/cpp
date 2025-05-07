#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public :
	void	attack();

	private :
	Weapon		Weapon_;
	std::string	name_;

};

#endif