#ifndef M_A_PHONEBOOK_HPP
#define M_A_PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

class Contact
{
	private:
	std::string	Darkest_secret_;
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	std::string	phone_number_;

	public:
	bool		set_first_name(std::string *str, int checker);
	bool		set_last_name(std::string *str, int checker);
	bool		set_nickname(std::string *str, int checker);
	bool		set_phone_number(std::string *str, int checker);
	bool		set_secret(std::string *str, int checker);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone(void);
	std::string	get_secret(void);
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
	int			count;
};

void	get_input(std::string *input);

void	add_contact(Phonebook *phone, std::string *input);

void	search_contact(Phonebook *phone, std::string *input);

#endif