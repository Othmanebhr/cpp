#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : _name(""), _HitPoint(100), _EnergyPoint(50), _AttackDammage(20), _GuardMode(false)
{
	std::cout << "Scavtrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _HitPoint(100), _EnergyPoint(50), _AttackDammage(20), _GuardMode(false)
{
	std::cout << "Scavtrap: Parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	this->_name = cpy._name;
	this->_HitPoint = cpy._HitPoint;
	this->_EnergyPoint = cpy._EnergyPoint;
	this->_AttackDammage = cpy._AttackDammage;
	this->_GuardMode = cpy._GuardMode;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoint = rhs._HitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_AttackDammage = rhs._AttackDammage;
		this->_GuardMode = rhs._GuardMode;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap: Destructor called." << std::endl; }

void	ScavTrap::guardGate()
{
	if (this->_GuardMode == true)
		std::cout << "ScavTrap: " << _name << " is already on guardmode." << std::endl;
	else
	{
		_GuardMode = true;
		std::cout << "ScavTrap: " << _name << " is now on guardmode." << std::endl;
	}
}

//geter
unsigned int	ScavTrap::getAttackDammage() { return _AttackDammage; }
unsigned int	ScavTrap::getEnergyPoint() { return _EnergyPoint; }
unsigned int	ScavTrap::getHitPoint() { return _HitPoint; }
std::string		ScavTrap::getName() { return _name; }
bool			ScavTrap::getGuarMode()	{ return _GuardMode; }

//setter
void	ScavTrap::setGuarMode(bool GM) {_GuardMode = GM; }
void	ScavTrap::setName(std::string name) { _name = name; }
void	ScavTrap::setHitPoint(unsigned int HP) { _HitPoint = HP; }
void	ScavTrap::setEnergyPoint(unsigned int EP) { _EnergyPoint = EP; }
void	ScavTrap::setAttackDammage(unsigned int AD) { _AttackDammage = AD; }