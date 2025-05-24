#include "../includes/AForm.hpp"

AForm::AForm(std::string name, unsigned int min_exec, unsigned int min_sign)
 : _name(name), _isSigned(false), _executed(false) ,_gradeSign(min_sign), _gradeExec(min_exec)
{
	if (min_sign < 1)
		throw GradeTooHighException();
	else if (min_sign > 150)
		throw GradeTooLowException();
	if (min_exec < 1)
		throw GradeTooHighException();
	else if (min_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& cpy)
 : _name(cpy._name), _isSigned(cpy._isSigned), _executed(false), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {}

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
		this->_executed = rhs._executed;	
	}
	return *this;
}

AForm::~AForm() {}

/*Getter*/
const std::string& AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSgned() const
{
	return _isSigned;
}

unsigned int AForm::getGradeSign() const
{
	return _gradeSign;
}

unsigned int AForm::getGradeExec() const
{
	return _gradeExec;
}

/*Setter*/
void	AForm::setIsSigned(bool Sign)
{
	_isSigned = Sign;
}

/*Member Function*/
void	AForm::beSigned(Bureaucrat& B)
{
	if (B.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	else
	{
		std::cout << "AForm " << "'" << _name << "'" << " signed!" << std::endl;
		_isSigned = true;
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_executed == true)
		throw AlreadyExecuted();
	if (this->_isSigned == false)
		throw IsNotSigned();
	else if (executor.getGrade() > this->_gradeExec)
		throw GradeTooLowException();
	else
	{
		_executed = true;
		this->Action();
	}
}

/*Exceptions*/
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::IsNotSigned::what() const throw()
{
	return "This Form isn't signed.";
}

const char *AForm::AlreadyExecuted::what() const throw()
{
	return "This form is already executed.";
}

/*Surcharge*/
std::ostream& operator<<(std::ostream& os, const AForm& F)
{
	std::cout << "AForm: " << F.getName() << " Grade level Exec required = " << F.getGradeExec() 
	<< ", Grade level Sign required = " << F.getGradeSign();
	return os;
}
