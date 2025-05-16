#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
	WrongCat();
	WrongCat(const WrongCat& cpy);
	WrongCat& operator=(const WrongCat& rhs);
	~WrongCat();

	void	makeSound()const ;
	private:

};

#endif