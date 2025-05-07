#include "../MAPhonebook.hpp"

static void	first_aff(void)
{
	std::cout << "Entrez une commande: ADD, SEARCH, EXIT." << std::endl;
	std::cout << "ADD:  Ajouter un contact." << std::endl;
	std::cout << "SEARCH: Rechercher un contact." << std::endl;
	std::cout << "EXIT: Quitter le programme." << std::endl;
}

bool	get_input(std::string *input)
{
	if (!std::getline(std::cin, *input))
	{
		system("clear");
		std::cout << "Fermeture du programme (EOF détecté)." << std::endl;
		return false;
	}
	if (*input == "EXIT")
	{
		system("clear");
		std::cout << "Have a good day!" << std::endl;
		return false;
	}
	return true;
}

int	main(int ac, char **av)
{
	Phonebook	phone;
	std::string	input;
	(void)av;

	if (ac != 1)
	{
		std::cout << "Wrong nb of args, please use only executable file." << std::endl;
		return 1;
	}
	system("clear");

	phone.set_idx();
	phone.count = 0;
	first_aff();
	std::cout << std::endl;
	while (true)
	{
		std::cout << "Please choose an option: (ADD, SEARCH, EXIT)" << std::endl;
		if (!get_input(&input))
			break ;
		if (input == "ADD")
		{
			system("clear");
			if (!add_contact(&phone, &input))
				break ;
		}
		else if (input == "SEARCH")
		{
			if (phone.get_idx() == 0 && phone.count == 0)
				std::cout << "Aucun contact ajoute!" << std::endl;
			else
				if (!search_contact(&phone, &input))
					break ;
		}
	}
	return 0;
}