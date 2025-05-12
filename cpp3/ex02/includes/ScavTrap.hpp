#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& cpy);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	guardGate();

	bool	getGuarMode();
	void	setGuarMode(bool GM);

	private:

	bool	_GuardMode;
};

#endif