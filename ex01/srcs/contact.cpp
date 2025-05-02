#include "../MAPhonebook.hpp"

bool	Contact::set_first_name(char *str)
{
	first_name_ = str;
	if (first_name_.length() < 2)
	{
		std::cout << "Please set a valid first_name, at least 2 letters" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::set_last_name(char *str)
{
	last_name_ = str;
	if (last_name_.length() < 2)
	{
		std::cout << "Please set a valid last_name, at least 2 letters" << std::endl;
		return (false);
	}
	return (true);
}
bool	Contact::set_nickname(char *str)
{
	nickname_ = str;
	if (nickname_.length() == 0)
	{
		std::cout << "Please set a valid nickname" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::set_phone_number(char *str)
{
	phone_number_ = atoi(str);
	if (phone_number_ < 1000)
	{
		std::cout << "Please set a valid number, at least 4 digit!" << std::endl;
		return (false);
	}
	return (true);
}