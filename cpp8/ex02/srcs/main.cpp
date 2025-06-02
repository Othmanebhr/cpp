#include "../includes/MutantStack.hpp"

/*
push() : ajouter un élément au sommet de la pile
pop() : retirer l'élément au sommet
top() : accéder à l'élément au sommet
empty() : vérifier si la pile est vide
size() : obtenir le nombre d'éléments
*/

int main()
{
	std::cout << "-------" << "test avec MutantStack:" << "-------" << std::endl;
	std::cout << std::endl;
	MutantStack<int> mstack;
	std::cout << "empty: " << mstack.empty() << std::endl;
	mstack.push(66);
	std::cout << "empty: " << mstack.empty() << std::endl;
	std::cout << "(test top) " << mstack.top() << std::endl;
	mstack.push(98);
	std::cout  << "(test top) " << mstack.top() << std::endl;

	mstack.push(87);
	mstack.push(364);
	mstack.push(17);
	mstack.push(71);
	mstack.push(8123);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "list: " << std::endl;
	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	

	std::cout << std::endl;
	std::cout << "-------" << "test avec vector:" << "-------" << std::endl;
	std::cout << std::endl;

	std::vector<int> vstack;
	std::cout << "empty: " << vstack.empty() << std::endl;
	vstack.push_back(66);
	std::cout << "empty: " << vstack.empty() << std::endl;
	vstack.push_back(98);

	vstack.push_back(87);
	vstack.push_back(364);
	vstack.push_back(17);
	vstack.push_back(71);
	vstack.push_back(8123);
	std::vector<int>::iterator Vit = vstack.begin();
	std::vector<int>::iterator Vite = vstack.end();
	std::cout << "list: " << std::endl;
	for (; Vit != Vite; Vit++)
		std::cout << *Vit << " ";
	std::cout << std::endl;
	
	return 0;
}