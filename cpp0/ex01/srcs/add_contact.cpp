#include "../MAPhonebook.hpp"

static bool add_part(std::string *input, bool (Contact::*setter)(std::string*, int), const std::string& prompt,
	int idx, Phonebook *phone)
{
	std::cout << prompt << std::endl;
	if (!get_input(input))
		return false;
	(phone->Contact_[idx].*setter)(input, 1);
	while (!(phone->Contact_[idx].*setter)(input, 0))
	{
		if (!get_input(input))
			return false;
	}
	system("clear");
	return true;
}

bool	add_contact(Phonebook *phone, std::string *input)
{
	if (phone->get_idx() == 8)
		phone->set_idx();
	int	idx = phone->get_idx();

	if (!add_part(input, &Contact::set_first_name, "Please set the first name:", idx, phone))
		return false;
	if (!add_part(input, &Contact::set_last_name, "Please set the last name:", idx, phone))
		return false;
	if (!add_part(input, &Contact::set_nickname, "Please set a nickname:", idx, phone))
		return false;
	if (!add_part(input, &Contact::set_phone_number, "Please set the number:", idx, phone))
		return false;
	if (!add_part(input, &Contact::set_secret, "Please set the darkest secret:", idx, phone))
		return false;

	phone->icr_idx();
	std::cout << "Your contact has been successfully added!" << std::endl;
	return true;
}