#include "../includes/Global.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& cpy) : AMateria(cpy) {}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone()
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}