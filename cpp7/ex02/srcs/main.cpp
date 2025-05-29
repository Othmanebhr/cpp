#include "../includes/Array.hpp"

int main()
{
	try
	{
		Array<int> test(5);
		std::cout << "Test.size = " << test.size() << std::endl;
	} catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<char> CharTest(4);
		std::cout << "Char array:" << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			CharTest[i] = '0';
			std::cout << CharTest[i];
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<char> CharTooFar(4);
		std::cout << "CharTooFar:" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			CharTooFar[i] = '0';
			std::cout << CharTooFar[i];
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<char *> empty;
		std::cout << "Trying empty[5]" << std::endl;
		std::cout << empty[5] << std::endl;
	} catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<int> test(-1);
		std::cout << "Test.size = " << test.size() << std::endl;
	} catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}