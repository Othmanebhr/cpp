#include "../includes/Form.hpp"

Form::Form(std::string name, unsigned int min_exec, unsigned int min_sign) : _name(name), _isSigned(false), _gradeSign(min_sign), _gradeExec(min_exec) {}

Form::Form(const Form& cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {}

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form() {}

/*Getter*/
const std::string& Form::getName() const
{
	return _name;
}

bool	Form::getIsSgned() const
{
	return _isSigned;
}

unsigned int Form::getGradeSign() const
{
	return _gradeSign;
}

unsigned int Form::getGradeExec() const
{
	return _gradeExec;
}

/*Member Function*/
void	Form::beSigned(Bureaucrat& B)
{
	if (B.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	else
	{
		std::cout << "Form " << "'" << _name << "'" << " signed!" << std::endl;
		_isSigned = true;
	}
}

/*Exceptions*/
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

/*Surcharge*/
std::ostream& operator<<(std::ostream& os, const Form& F)
{
	std::cout << "Form: " << F.getName() << " Grade level Exec required = " << F.getGradeExec() 
	<< ", Grade level Sign required = " << F.getGradeSign();
	return os;
}
