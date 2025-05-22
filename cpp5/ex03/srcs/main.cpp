#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 

int main()
{
	srand(time(NULL));
	
	std::cout << "\n=== CREATING BUREAUCRATS ===" << std::endl;
	Bureaucrat boss("Boss", 5);
	Bureaucrat assistant("Assistant", 45);
	
	std::cout << "\n=== TESTING INTERN CLASS ===" << std::endl;
	Intern someRandomIntern;
	
	std::cout << "\n=== TEST 1: CREATE SHRUBBERY FORM ===" << std::endl;
	AForm* form1 = someRandomIntern.Makeform("ShrubberyCreationForm", "Garden");
	if (form1) {
		std::cout << "Form created successfully: " << *form1 << std::endl;
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}
	
	std::cout << "\n=== TEST 2: CREATE ROBOTOMY FORM ===" << std::endl;
	AForm* form2 = someRandomIntern.Makeform("RobotomyRequest", "Bender");
	if (form2) {
		std::cout << "Form created successfully: " << *form2 << std::endl;
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}
	
	std::cout << "\n=== TEST 3: CREATE PRESIDENTIAL PARDON FORM ===" << std::endl;
	AForm* form3 = someRandomIntern.Makeform("PresidentialPardon", "Douglas Adams");
	if (form3) {
		std::cout << "Form created successfully: " << *form3 << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}
	
	std::cout << "\n=== TEST 4: TRY TO CREATE INVALID FORM ===" << std::endl;
	AForm* form4 = someRandomIntern.Makeform("NonExistentForm", "Nobody");
	if (form4) {
		std::cout << "Form created successfully: " << *form4 << std::endl;
		delete form4;
	} else {
		std::cout << "Form creation failed as expected." << std::endl;
	}
	
	std::cout << "\n=== TESTING INTERN COPY ===" << std::endl;
	Intern anotherIntern = someRandomIntern;  // Using copy constructor
	AForm* form5 = anotherIntern.Makeform("PresidentialPardon", "Another Criminal");
	if (form5) {
		std::cout << "Form created by copied intern: " << *form5 << std::endl;
		delete form5;
	}

	return 0;
}