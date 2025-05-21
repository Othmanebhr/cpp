#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name), _grade(cpy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
		//this->_name = _name; // const
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::setGrade(unsigned int new_grade) { this->_grade = new_grade; }

void Bureaucrat::gradeUp()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::gradeDown()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high, Grade 1 is Maximum!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low, Grade 150 is Minimum!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
	os << Bureaucrat.getName() << ", Bureaucrat grade: " << Bureaucrat.getGrade();
	return os;
}