#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public :
	void	attack();

	private :
	Weapon		Weapon_;
	std::string	name_;

};

#endif