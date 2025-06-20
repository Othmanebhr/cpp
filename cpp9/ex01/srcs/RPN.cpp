#include "../includes/RPN.hpp"

#define ERR_IF "Error: invalid format."

/*
push() : ajouter un élément au sommet de la pile
pop() : retirer l'élément au sommet
top() : accéder à l'élément au sommet
empty() : vérifier si la pile est vide
size() : obtenir le nombre d'éléments
*/

bool RPN::is_between(char c)
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
	int save = -1;
	for (size_t i = 0; i < _calcul.size(); i++)
	{
		
	}
}