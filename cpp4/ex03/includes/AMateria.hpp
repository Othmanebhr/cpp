#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	public:
	AMateria(std::string const & type);
	virtual ~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() = 0;
	virtual void use(ICharacter& target);

	protected:

};

#endif