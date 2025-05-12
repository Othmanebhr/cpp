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

	std::string		getName();
	bool			getGuarMode();
	unsigned int	getHitPoint();
	unsigned int	getEnergyPoint();
	unsigned int	getAttackDammage();

	void			setName(std::string name);
	void			setGuarMode(bool GM);
	void			setHitPoint(unsigned int HP);
	void			setEnergyPoint(unsigned int EP);
	void			setAttackDammage(unsigned int AD);

	private:
	std::string		_name;
	unsigned int	_HitPoint;
	unsigned int	_EnergyPoint;
	unsigned int	_AttackDammage;
	bool			_GuardMode;
};

#endif