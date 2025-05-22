#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern& cpy);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm	*Makeform(std::string Form, std::string target);

	private:

};

#endif