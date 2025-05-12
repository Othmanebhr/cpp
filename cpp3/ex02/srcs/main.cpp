#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
	// ClapTrap Default_constructor;
	// ClapTrap othmane("Othmane");

	// std::cout << std::endl;
	// othmane.attack("Yanis");
	// othmane.beRepaired(2);
	// othmane.takedamage(3);
	// std::cout << std::endl;

	// ScavTrap Default_constructor2;
	// ScavTrap Maxime("Maxime");
	// std::cout << std::endl;
	// Maxime.attack("Miqdad");
	// Maxime.beRepaired(3);
	// Maxime.takedamage(2);
	// Maxime.guardGate();
	// Maxime.guardGate();
	// std::cout << std::endl;

	FragTrap Default_constructor3;
	FragTrap Yanis("Yanis");
	std::cout << std::endl;
	Yanis.attack("Miqdad");
	Yanis.beRepaired(3);
	Yanis.takedamage(2);
	Yanis.highFivesGuys();
	std::cout << std::endl;


	return 0;
}