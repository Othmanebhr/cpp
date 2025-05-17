#ifndef CURE_HPP
#define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
	Cure();
	Cure(const Cure& cpy);
	Cure& operator=(const Cure& rhs);
	~Cure();

	AMateria* clone();
	void	use(ICharacter& target);

	private:

};


#endif