#include "../includes/Global.hpp"

int main()
{
	std::cout << "=== MateriaSource learning ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); //full

	std::cout << "\n=== Character creation and equip ===" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); //full
	delete tmp;

	std::cout << "\n=== Use Materia ===" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); //index +1

	std::cout << "\n=== Unequip and memory management ===" << std::endl;
	AMateria* unequipped = ((Character*)me)->getInventory(1);
	if (unequipped)
	{
		me->unequip(1);
		delete unequipped;
	}
	else
		std::cout << "No materia at this index to unequip" << std::endl;
	me->use(1, *bob); //"Please select a valid index"

	std::cout << "\n=== Deep copy test ===" << std::endl;
	Character* clone = new Character(*(Character*)me);
	clone->use(0, *bob);
	clone->use(2, *bob);

	std::cout << "\n=== Assignment operator test ===" << std::endl;
	Character assign("assign");
	assign = *(Character*)me;
	assign.use(0, *bob);

	std::cout << "\n=== MateriaSource copy test ===" << std::endl;
	MateriaSource* src2 = new MateriaSource(*(MateriaSource*)src);
	AMateria* tmp2 = src2->createMateria("cure");
	if (tmp2)
		std::cout << "src2 can create cure materia" << std::endl;
	else
		std::cout << "src2 cannot create cure materia" << std::endl;
	delete tmp2;

	std::cout << "\n=== Clean up ===" << std::endl;
	delete bob;
	delete me;
	delete clone;
	delete src;
	delete src2;

	std::cout << "=== End of tests ===" << std::endl;
	return 0;
}