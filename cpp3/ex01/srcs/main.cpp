#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap Default_constructor;
    ClapTrap othmane("Othmane");

    std::cout << std::endl;
    othmane.attack("Yanis");
    othmane.beRepaired(2);
    othmane.takedamage(3);

    std::cout << std::endl;
    othmane.setEnergyPoint(0);
    othmane.attack("Yanis");
    othmane.beRepaired(2);
    othmane.takedamage(3);

    std::cout << std::endl;
    othmane.setHitPoint(0);
    othmane.attack("Yanis");
    othmane.beRepaired(2);
    othmane.takedamage(3);
    std::cout << std::endl;

    return 0;
}