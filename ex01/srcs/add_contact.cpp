#include "../MAPhonebook.hpp"

static void	del_first(void)
{

}

void	add_contact(Phonebook *phone, std::string *input)
{
	while (true)
	{
		// if (phone->get_idx() == 8)
		// 	del_first();
		while (phone->Contact_->set_first_name() != true)
		{
			get_input()
		}
	}
}