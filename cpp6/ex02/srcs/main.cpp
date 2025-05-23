#include "../includes/Base.hpp"

Base *generate()
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;//
	switch (random)
	{
		case 0:
			std::cout << "Creation Type: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Creation Type: B" << std::endl;
			return new B();
		case 2:
			std::cout << "Creation Type: C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointeur = L'objet est de type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointeur = L'objet est de type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointeur = L'objet est de type C" << std::endl;
	else
		std::cout << "Pointeur = inconnu" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference = L'objet est de type A" << std::endl;
		return ;
	} catch (std::exception &) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference = L'objet est de type B" << std::endl;
		return ;
	} catch(std::exception &) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference = L'objet est de type C" << std::endl;
		return ;
	}catch(const std::exception&) {}
	std::cout << "Reference = inconnu" << std::endl;
}

int main()
{
	Base *obj = generate();
	identify(obj);
	identify(*obj);

	std::cout << std::endl;

	identify(NULL);

	if (obj)
		delete obj;
	return 0;
}