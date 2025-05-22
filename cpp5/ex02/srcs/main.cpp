#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 

int main()
{
	srand(time(NULL));
	ShrubberyCreationForm shrubbery("Garden");
	RobotomyRequestForm robotomy("Target");
	PresidentialPardonForm pardon("Criminal");
	
	Bureaucrat highLevel("Boss", 5);
	Bureaucrat midLevel("Manager", 50);
	Bureaucrat lowLevel("Intern", 140);
	
	std::cout << "\n=== TESTING WITHOUT SIGNING FIRST ===" << std::endl;
	std::cout << "\nTrying to execute unsigned forms:" << std::endl;
	try {
		highLevel.executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TESTING SHRUBBERY FORM ===" << std::endl;
	std::cout << "Form info: " << shrubbery << std::endl;
	std::cout << "\nSigning attempts:" << std::endl;
	lowLevel.signForm(shrubbery);    // Devrait réussir (grade 140, requis 145)
	
	std::cout << "\nExecution attempts:" << std::endl;
	lowLevel.executeForm(shrubbery); // Devrait échouer (grade 140, requis 137)
	midLevel.executeForm(shrubbery); // Devrait réussir
	
	std::cout << "\n=== TESTING ROBOTOMY FORM ===" << std::endl;
	std::cout << "Form info: " << robotomy << std::endl;
	std::cout << "\nSigning attempts:" << std::endl;
	lowLevel.signForm(robotomy);     // Devrait échouer (grade 140, requis 72)
	midLevel.signForm(robotomy);     // Devrait réussir
	
	std::cout << "\nExecution attempts:" << std::endl;
	midLevel.executeForm(robotomy);  // Devrait échouer (grade 50, requis 45)
	highLevel.executeForm(robotomy); // Devrait réussir (50% de chance)
	highLevel.executeForm(robotomy); // Essayons encore
	
	std::cout << "\n=== TESTING PRESIDENTIAL PARDON FORM ===" << std::endl;
	std::cout << "Form info: " << pardon << std::endl;
	std::cout << "\nSigning attempts:" << std::endl;
	midLevel.signForm(pardon);       // Devrait échouer
	highLevel.signForm(pardon);      // Devrait réussir
	
	std::cout << "\nExecution attempts:" << std::endl;
	midLevel.executeForm(pardon);    // Devrait échouer
	highLevel.executeForm(pardon);   // Devrait réussir
	
	std::cout << "\n=== TESTING EXCEPTIONS ===" << std::endl;
	try {
		highLevel.executeForm(pardon); // Déjà exécuté
	} catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
	
	return 0;
}