#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
	MateriaSource();
	MateriaSource(const MateriaSource& cpy);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void	learnMateria(AMateria *Materia);
	AMateria *createMateria(const std::string& type);

	private:
	AMateria*	_materia[4];
};

#endif