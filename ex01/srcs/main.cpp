#include "../MAPhonebook.hpp"

static void	first_aff(void)
{
	std::cout << "Entrez une commande: ADD, SEARCH, EXIT." << std::endl;
	std::cout << "ADD:  Ajouter un contact." << std::endl;
	std::cout << "SEARCH: Rechercher un contact." << std::endl;
	std::cout << "EXIT: Quitter le programme." << std::endl;
}

void	get_input(std::string *input)
{
	std::getline(std::cin, *input);
	if (*input == "EXIT")
	{
		system("clear");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	Phonebook	phone;
	std::string	input;

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
		get_input(&input);
		if (input == "ADD")
		{
			system("clear");
			add_contact(&phone, &input);
		}
		else if (input == "SEARCH")
			search_contact(&phone, &input);
	}
	system("clear");
	return 0;
}