#include "../includes/Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& cpy)
{
	this->_name = cpy._name;
	for (size_t i = 0; i < 4; i++)
	{
		if (cpy._inventory[i])
			this->_inventory[i] = cpy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	_inventory[idx] = NULL;
}//delete?


void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) &&_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Please select a valid index." << std::endl;
}

std::string const & Character::getName() const { return _name; }
