#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& cpy) // = default
{
	(void)cpy;
}

Intern& Intern::operator=(const Intern& rhs) // = default
{
	(void)rhs;
	return *this;
}

Intern::~Intern() {}

AForm	*Intern::Makeform(std::string Form, std::string target)
{
	std::string Diff_Form[] = {"ShrubberyCreationForm", "RobotomyRequest", "PresidentialPardon"};

	size_t i = 0;
	while(i < 3 && Diff_Form[i] != Form)
		i++;
	switch(i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Coundn't create form: " << Form << std::endl;
			return NULL;
	}
}