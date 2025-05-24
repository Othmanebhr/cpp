#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Bob("Bob", 1);
		std::cout << Bob << std::endl; 
		Bob.gradeDown();
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
		Maxime.gradeUp();
		std::cout << Maxime << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Othmane("Othmane", 1);
		std::cout << Othmane << std::endl;
		Othmane.gradeUp();
		std::cout << Othmane << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "err: Othmane: ";
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Miqdad("Miq", 0);
		std::cout << Miqdad << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "err: Miqdad: ";
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Yanis("Yanis", 151);
		std::cout << Yanis << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "err: Yanis: ";
		std::cerr << e.what() << std::endl;
	}
	return 0;
}