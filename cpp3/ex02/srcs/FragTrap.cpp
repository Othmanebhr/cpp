#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDammage = 30;
	std::cout << "FragTrap: default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDammage = 30;
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

FragTrap::~FragTrap() { std::cout << "FragTrap: Destructor called." << std::endl; }

void	FragTrap::highFivesGuys()
{
	std::cout << this->_name << " Say: Who want a Highfive?" << std::endl;
}