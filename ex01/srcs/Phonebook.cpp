#include "../MAPhonebook.hpp"

void	Phonebook::set_idx(void)
{
	idx_ = 0;
	count = 1;
}

bool	Phonebook::icr_idx(void)
{
	if (idx_ < 8)
	{
		idx_++;
		return (true);
	}
	return (false);
}

int	Phonebook::get_idx(void)
{
	return idx_;
}