#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	Form rncp("Transcendance", 56, 21);
	Bureaucrat	Maxime("Maxime", 2);

	std::cout << rncp << std::endl;
	Maxime.signForm(rncp);
}