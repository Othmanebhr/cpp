#include "../MAPhonebook.hpp"

bool	Contact::set_first_name(std::string *str, int checker)
{
	first_name_ = *str;
	if (!str || first_name_.length() < 2)
	{
		if (checker == 0)
			std::cout << "Please set a valid first_name, at least 2 letters" << std::endl;
		return false;
	}
	return true;
}

bool	Contact::set_last_name(std::string *str, int checker)
{
	last_name_ = *str;
	if (!str || last_name_.length() < 2)
	{
		if (checker == 0)
			std::cout << "Please set a valid last_name, at least 2 letters" << std::endl;
		return false;
	}
	return true;
}
bool	Contact::set_nickname(std::string *str, int checker)
{
	nickname_ = *str;
	if (!str || nickname_.length() == 0)
	{
		if (checker == 0)
			std::cout << "Please set a valid nickname" << std::endl;
		return false;
	}
	return true;
}

bool	Contact::set_phone_number(std::string *str, int checker)
{
	phone_number_ = *str;
	if (!str || phone_number_.length() < 4)
	{
		if (checker == 0)
			std::cout << "Please set a valid number, only digits are allowed and a minimum of 4 digits!" << std::endl;
		return false;
	}
	for (size_t i = 0; i < phone_number_.length(); ++i)
	{
		if (!std::isdigit(phone_number_[i]))
		{
			if (checker == 0)
				std::cout << "Please set a valid number, only digits are allowed and a minimum of 4 digits!" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::set_secret(std::string *str, int checker)
{
	Darkest_secret_ = *str;
	if (!str)
	{
		if (checker == 0)
			std::cout << "Please set a valid secret or at least a blank" << std::endl;
		return false;
	}
	return true;
}

std::string	Contact::get_first_name(void)
{
	return first_name_;
}
std::string	Contact::get_last_name(void)
{
	return last_name_;
}
std::string	Contact::get_nickname(void)
{
	return nickname_;
}
std::string	Contact::get_phone(void)
{
	return phone_number_;
}