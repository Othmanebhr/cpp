#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _GuardMode(false)
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDammage(20);
	std::cout << "Scavtrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _GuardMode(false)
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDammage(20);
	std::cout << "Scavtrap: Parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	*this = cpy;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->_GuardMode = rhs._GuardMode;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap: Destructor called." << std::endl; }

bool	ScavTrap::getGuarMode() { return _GuardMode; }

void	ScavTrap::setGuarMode(bool GM)
{
	if (_GuardMode == GM)
	{
		if (GM)
			std::cout << "Scavtrap: " << this->getName() << " is already in guarmode." << std::endl;
		else
			std::cout << "Scavtrap: " << this->getName() << " is already chillin." << std::endl;
	}
	else
	{
		_GuardMode = GM;
		if (GM)
			std::cout << "Scavtrap: " << this->getName() << " is now in guarmode." << std::endl;
		else
			std::cout << "Scavtrap: " << this->getName() << " is now chillin." << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	this->setGuarMode(true);
}