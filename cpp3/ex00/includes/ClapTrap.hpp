#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& cpy);
    ClapTrap& operator=(ClapTrap& rhs);
    ~ClapTrap();

    void    attack(const std::string& target);
    void    takedamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    private:
    std::string _name;
    unsigned int _HitPoint;
    unsigned int _EnergyPoint;
    unsigned int _AttackDammage;

};

#endif