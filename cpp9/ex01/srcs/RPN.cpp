#include "../includes/RPN.hpp"

#define ERR_IF "Error: invalid format."

/*
push() : ajouter un élément au sommet de la pile
pop() : retirer l'élément au sommet
top() : accéder à l'élément au sommet
empty() : vérifier si la pile est vide
size() : obtenir le nombre d'éléments
*/

bool is_between(char c)
{
	if (std::isdigit(c))
	{
		if (c >= '0' && c <= '9')
			return true;
	}
	return false;
}

bool RPN::calculate()
{
	for (size_t i = 0; i < _calcul.size(); i++)
	{
		if (_calcul[i] != '+' && _calcul[i] != '-' && _calcul[i] != '/' && _calcul[i] != '*' && _calcul[i] != ' ' && _calcul[i] != '\t')
		{
			if (is_between(_calcul[i]))
				continue;
			std::cerr << ERR_IF << std::endl;
			return false;
		}
	}
	for (size_t i = 0; i < _calcul.size(); i++)
	{
		char c = _calcul[i];
		if (c == ' ' || c == '\t')
			continue;
		if (is_between(c))
		{
			int nb = c - '0';
			_contain.push(nb);
		}
		else
		{
			if (_contain.size() < 2)
			{
				std::cout << ERR_IF << std::endl;
				return false;
			}
			int b = _contain.top();
			_contain.pop();
			int a = _contain.top();
			_contain.pop();
			switch (c)
			{
				case '+':
					_contain.push(a + b);
					break;
				case '-':
					_contain.push(a - b);
					break;
				case '*':
					_contain.push(a * b);
					break;
				case '/':
					if (b == 0)
					{
						std::cerr << "Error: cannot divide by 0." << std::endl;
						return false; 
					}
					_contain.push(a / b);
					break;
				default:
					std::cout << ERR_IF << std::endl;
					return false;
			}
		}
	}
	if (_contain.size() != 1)
	{
		std::cerr << ERR_IF << std::endl;
		return false;
	}
	std::cout << _contain.top() << std::endl;
	return true;
}