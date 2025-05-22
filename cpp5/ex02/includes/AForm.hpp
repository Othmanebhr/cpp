#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	AForm(std::string name, unsigned int min_exec, unsigned int min_sign);
	AForm(const AForm& cpy);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	const std::string& getName()const;
	bool		getIsSgned()const;
	unsigned int getGradeSign()const;
	unsigned int getGradeExec()const;
	void		setIsSigned(bool Sign);

	void beSigned(Bureaucrat& B);
	void execute(Bureaucrat const & executor)const;

	virtual void Action()const = 0;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class IsNotSigned : public std::exception
	{
		virtual const char *what() const throw();
	};

	class AlreadyExecuted : public std::exception
	{
		virtual const char *what() const throw();
	};

	private:
	const std::string _name;
	bool	_isSigned;
	mutable bool	_executed;
	const unsigned int	_gradeSign; 
	const unsigned int	_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& F);

#endif