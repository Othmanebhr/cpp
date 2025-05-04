#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
		{
			// std::string s = av[i];
			for (size_t j = 0; av[i][j]; j++)
				std::cout << (char)std::toupper(av[i][j]);
				// std::cout << (char)std::toupper(s[j]);
			if (av[i + 1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
