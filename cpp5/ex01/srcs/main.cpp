#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try
	{
		Form rncp("Transcendance", 56, 21);
		Bureaucrat	Maxime("Maxime", 2);
		std::cout << rncp << std::endl;
		Maxime.signForm(rncp);
	}
	catch(const std::exception& e)
	{
		std::cout << "Maxime & rncp:";
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form rncp("Minishell", 0, 21);
		// Bureaucrat	Othmane("Othmane", 2);
		// std::cout << rncp << std::endl;
		// Othmane.signForm(rncp);
	}
	catch(const std::exception& e)
	{
		std::cout << "Minishell :";
		std::cerr << e.what() << std::endl;
	}
}