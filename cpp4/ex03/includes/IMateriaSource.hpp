#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learMateria(AMateria *) = 0;
	virtual void createMateria(std::string const & type) = 0;

	private:
};

#endif