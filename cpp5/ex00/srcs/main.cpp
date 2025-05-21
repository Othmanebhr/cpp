#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Bob("Bob", 6);
		std::cout << Bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Maxime("Maxime", 150);
		std::cout << Maxime << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Miqdad("Miq", 1);
		std::cout << Miqdad << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Yanis("Yanis", 151);
		std::cout << Yanis << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Yanis: ";
		std::cerr << e.what() << std::endl;
	}
	return 0;
}