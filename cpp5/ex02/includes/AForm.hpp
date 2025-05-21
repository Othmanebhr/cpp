#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	Form(std::string name, unsigned int min_exec, unsigned int min_sign);
	Form(const Form& cpy);
	Form& operator=(const Form& rhs);
	~Form();

	const std::string& getName()const;
	bool		getIsSgned()const;
	unsigned int getGradeSign()const;
	unsigned int getGradeExec()const;

	void beSigned(Bureaucrat& B);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	private:
	const std::string _name;
	bool	_isSigned;
	const unsigned int	_gradeSign; 
	const unsigned int	_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& F);

#endif