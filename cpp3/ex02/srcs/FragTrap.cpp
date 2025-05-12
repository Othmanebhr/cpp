#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDammage(30);
	std::cout << "FragTrap: default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDammage(30);
	std::cout << "FragTrap: Parameterized constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy)
{
	*this = cpy;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap() { std::cout << "ScavTrap: Destructor called." << std::endl; }

