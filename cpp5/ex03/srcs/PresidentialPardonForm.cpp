#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 5, 25), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->setIsSigned(rhs.getIsSgned());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/*Member fct*/
void	PresidentialPardonForm::Action() const
{
	std::cout << _target << " has been pardoned by Zaphob Beeblebrox" << std::endl;
}