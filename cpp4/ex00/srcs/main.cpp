#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Main fournie:" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Test perso: Stupid Animals" << std::endl;
	std::cout << std::endl;

	WrongAnimal	*StupidCat = new WrongCat();
	StupidCat->getType();
	StupidCat->makeSound();
	delete StupidCat;

	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Test Perso: Animals" << std::endl;
	std::cout << std::endl;

	Animal	*Random = new Animal();
	Random->makeSound();
	delete Random;
	std::cout << std::endl;

	Cat		*Lechat = new Cat();
	Lechat->makeSound();
	delete Lechat;
	std::cout << std::endl;

	Dog		Lechien;
	Lechien.makeSound();
	
	return 0;
}