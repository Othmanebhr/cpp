#include "../includes/Global.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& cpy) : AMateria(cpy) {}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone()
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}