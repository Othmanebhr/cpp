#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& cpy);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap(); // a voir le "virtual"

	void	guardGate();

	std::string		ScavTrap::getName();
	bool			ScavTrap::getGuarMode();
	unsigned int	ScavTrap::getHitPoint();
	unsigned int	ScavTrap::getEnergyPoint();
	unsigned int	ScavTrap::getAttackDammage();

	void			ScavTrap::setName(std::string name);
	void			ScavTrap::setGuarMode(bool GM);
	void			ScavTrap::setHitPoint(unsigned int HP);
	void			ScavTrap::setEnergyPoint(unsigned int EP);
	void			ScavTrap::setAttackDammage(unsigned int AD);

	private:
	std::string		_name;
	unsigned int	_HitPoint;
	unsigned int	_EnergyPoint;
	unsigned int	_AttackDammage;
	bool			_GuardMode;
};

#endif