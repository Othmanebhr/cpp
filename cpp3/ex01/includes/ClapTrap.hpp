#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cpy);
	ClapTrap& operator=(const ClapTrap& rhs);
	virtual ~ClapTrap();

	void	attack(const std::string& target);
	void	takedamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string		getName();
	unsigned int	getHitPoint();
	unsigned int	getEnergyPoint();
	unsigned int	getAttackDammage();

	void	setName(std::string name);
	void	setHitPoint(unsigned int HP);
	void	setEnergyPoint(unsigned int EP);
	void	setAttackDammage(unsigned int AD);

	protected: // achanger cpp3
	std::string		_name;
	unsigned int	_HitPoint;
	unsigned int	_EnergyPoint;
	unsigned int	_AttackDammage;

};

#endif