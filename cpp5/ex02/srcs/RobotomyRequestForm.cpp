#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 45, 72), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->setIsSigned(rhs.getIsSgned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char *RobotomyRequestForm::NoLuck::what() const throw()
{
	return "Robotomy Failed";
}

void RobotomyRequestForm::Action() const
{

	int random_number;
	random_number = rand() % 2;

	if (random_number == 0)
		std::cout << "##########" << _target << " has been robotomized" << "##########" << std::endl;
	else
		throw NoLuck();
}