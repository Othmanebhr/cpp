#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& cpy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (cpy._materia[i])
			this->_materia[i] = cpy._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria *Materia)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = Materia;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}