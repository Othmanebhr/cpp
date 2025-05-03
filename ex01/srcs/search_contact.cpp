#include "../MAPhonebook.hpp"

static std::string format_field(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

static void print_line(size_t idx, Contact ctc)
{
	std::cout << "|" << std::setw(10) << idx
			<< "|" << format_field(ctc.get_first_name())
			<< "|" << format_field(ctc.get_last_name())
			<< "|" << format_field(ctc.get_nickname())
			<< "|" << std::endl;
}

static void print_full_contact(Phonebook *phone)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|  INDEX   |FIRST_NAME| LAST_NAME| NICKNAME |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (size_t i = 0; i < phone->get_idx(); i++)
	{
		print_line(i, phone->Contact_[i]);
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void search_contact(Phonebook *phone, std::string *input)
{
	print_full_contact(phone);
	std::cout << "Please put the index you are serching for:" << std::endl;
	int	i_idx;
	std::string check;
	while (true)
	{
		get_input(input);
		check = *input;
		int		checker = 0;
		for (int i = 0; i < check.length(); i++)
		{
			if (!std::isdigit(check[i]))
			{
				std::cout << "Please use only digits and a valid input:" << std::endl;
				checker = 1;
				break;
			}
		}
		if (checker == 1)
			continue ;
		i_idx = stoi(check);
		if ((i_idx >= 0 && i_idx <= 8) && i_idx <= phone->get_idx())
			break;
		else 
			std::cout << "Please use only digits and a valid input:" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Contact:" << std::endl;
	std::cout << "First name: " << phone->Contact_[i_idx].get_first_name() << std::endl;
	std::cout << "Last name: " << phone->Contact_[i_idx].get_last_name() << std::endl;
	std::cout << "Nickname: " << phone->Contact_[i_idx].get_nickname() << std::endl;
	std::cout << "Phone number: " << phone->Contact_[i_idx].get_phone() << std::endl;
}