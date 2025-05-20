#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
	Character(std::string name);
	Character(const Character& cpy);
	Character& operator=(const Character& rhs);
	~Character();

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	std::string const & getName() const;
	AMateria	*getInventory(int idx) const;

	private:
	std::string _name;
	AMateria *_inventory[4];
};

#endif