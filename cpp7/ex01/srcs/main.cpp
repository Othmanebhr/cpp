#include "../includes/iter.hpp"

void ft_toupper(char &c)
{
	c = std::toupper(c);
}

int main()
{
	char str[] = "test";
	std::cout << "before: " << str << std::endl;
	::iter(str, strlen(str), ft_toupper);
	std::cout << "After: " << str << std::endl;
}