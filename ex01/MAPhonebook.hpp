#ifndef M_A_PHONEBOOK_HPP
#define M_A_PHONEBOOK_HPP

#include <cctype>
#include <iostream>

class Contact
{
	private:
	std::string	Darkest_secret_;
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	int			phone_number_;

	public:
	bool	set_first_name(char *str);
	bool	set_last_name(char *str);
	bool	set_nickname(char *str);
	bool	set_phone_number(char *str);
};

class Phonebook
{
	private:
	int			idx_;
	
	public:
	Contact		Contact_[8];
	void		set_idx();
	bool		icr_idx();
	int			get_idx();
};

void	get_input(std::string *input);

void	add_contact(Phonebook *phone, std::string *input);

#endif