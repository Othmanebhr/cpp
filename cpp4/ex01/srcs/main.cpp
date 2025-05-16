#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// Animal	*tab[5];

	// /*Tab for subject*/
	// for (int i = 0; i < 5; i++)
	// {
	// 	if (i % 2)
	// 	{
	// 		tab[i] = new Cat();
	// 		std::cout << tab[i]->getType() << " " << i << " said:" << std::endl;
	// 		tab[i]->makeSound();
	// 		std::cout << std::endl;
	// 	}
	// 	else
	// 	{
	// 		tab[i] = new Dog();
	// 		std::cout << tab[i]->getType() << " " << i << " said:" << std::endl;
	// 		tab[i]->makeSound();
	// 		std::cout << std::endl;
	// 	}
	// }
	// for (int i = 0; i < 5; i++)
	// 	delete tab[i];

	/*IDEAS*/
	/*Cat*/
	// Cat chat;

	// chat.getBrain()->setIdeas(1, "Manger des croquettes.");
	// std::cout << chat.getBrain()->getIdea(1) << std::endl;
	// chat.getBrain()->setIdeas(2, "Manger des croquettes encore.");
	// std::cout << chat.getBrain()->getIdea(2) << std::endl;
	// chat.getBrain()->setIdeas(3, "Manger des croquettes encore encore.");
	// std::cout << chat.getBrain()->getIdea(3) << std::endl;;
	// chat.getBrain()->setIdeas(4, "Manger des croquettes encore encore encore.");
	// std::cout << chat.getBrain()->getIdea(4) << std::endl;
	// chat.getBrain()->setIdeas(4563, "Stupide.");
	// std::cout << chat.getBrain()->getIdea(4563) << std::endl;

	/*Cat*/
	Dog chien;

	chien.getBrain()->setIdeas(1, "Manger des croquettes.");
	std::cout << chien.getBrain()->getIdea(1) << std::endl;
	chien.getBrain()->setIdeas(2, "Manger des croquettes encore.");
	std::cout << chien.getBrain()->getIdea(2) << std::endl;
	chien.getBrain()->setIdeas(3, "Manger des croquettes encore encore.");
	std::cout << chien.getBrain()->getIdea(3) << std::endl;;
	chien.getBrain()->setIdeas(4, "Manger des croquettes encore encore encore.");
	std::cout << chien.getBrain()->getIdea(4) << std::endl;
	chien.getBrain()->setIdeas(4563, "Stupide.");
	std::cout << chien.getBrain()->getIdea(4563) << std::endl;
	return 0;
}