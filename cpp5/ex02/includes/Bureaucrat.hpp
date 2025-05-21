#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
	Bureaucrat(std::string _name);
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	const std::string&	getName() const;
	unsigned int	getGrade() const;
	void			setGrade(unsigned int new_grade);
	void			gradeUp();
	void			gradeDown();
	void			signForm(Form& F);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:
	const std::string _name;
	unsigned int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif