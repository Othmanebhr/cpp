#include "../includes/Span.hpp"

int main()
{
	std::cout << "--------Test Subject--------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan();

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Span test(8);
		for (size_t i = 0; i < 8; i++)
			test.addNumber(i);

		std::cout << "Shortest Span = " << test.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Span test(0);
		std::cout << "Shortest Span = " << test.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}
}