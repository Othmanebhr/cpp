#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->setIsSigned(rhs.getIsSgned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::FailOutf::what() const throw()
{
	return "Fail to open Outfile";
}

void	ShrubberyCreationForm::Action() const
{
	std::ofstream outfile;
	std::string filename = _target + "_Shrubbery";

	outfile.open(filename.c_str());
	if (!outfile.is_open())
		throw FailOutf();
	outfile << "       *       " << std::endl;
	outfile << "      ***      " << std::endl;
	outfile << "     *****     " << std::endl;
	outfile << "    *******    " << std::endl;
	outfile << "   *********   " << std::endl;
	outfile << "  ***********  " << std::endl;
	outfile << " ************* " << std::endl;
	outfile << "***************" << std::endl;
	outfile << "      |||      " << std::endl;
	outfile << "      |||      " << std::endl;
	outfile.close();
	std::cout << "Shrubbery created in file: " << filename << std::endl;
}