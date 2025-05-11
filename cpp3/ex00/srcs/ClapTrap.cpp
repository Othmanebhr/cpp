#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _HitPoint(10), _EnergyPoint(10), _AttackDammage(0)
{
    std::cout << "Default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDammage(0)
{
    std::cout << "Parameterized constructor has been called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
    if (this != &cpy)
    {
        _name   = cpy._name;
        _HitPoint = cpy._HitPoint;
        _EnergyPoint = cpy._EnergyPoint;
        _AttackDammage = cpy._AttackDammage;
    }
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        _HitPoint = rhs._HitPoint;
        _EnergyPoint = rhs._EnergyPoint;
        _AttackDammage = rhs._AttackDammage;
    }
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_HitPoint <= 0)
        std::cout << "Claptrap: " << _name << "is dead." << std::endl;
    if (_EnergyPoint > 0)
    {
        std::cout << "Claptrap: " << _name << " attacks " << target << 
        " causing " << _AttackDammage << " point of dammage." << std::endl;
    }
    else
        std::cout << "Claptrap: " << _name << 
        " have no energy left, he can't attack" << std::endl;
    _EnergyPoint--;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoint <= 0)
        std::cout << "Claptrap: " << _name << "is dead." << std::endl;
    if (_EnergyPoint > 0)
    {
        std::cout << "Claptrap: " << _name << " use heal, " << amount << 
        " HP have been regains!" << std::endl;
    }
    else
        std::cout << "Claptrap: " << _name << 
        " have no energy left, he can't heal itself" << std::endl;
    _EnergyPoint--;
}

void    ClapTrap::takedamage(unsigned int amount)
{
    if (_HitPoint <= 0)
        std::cout << "Claptrap: " << _name << "is already dead." << std::endl;
    else
    {
        _HitPoint -= amount;
        if (_HitPoint <= 0)
            std::cout << "Claptrap: " << _name << " has taken " << amount 
            << " he is now dead." << std::endl;
        else
            std::cout << "Claptrap: " << _name << " has taken " << amount 
            << " dammage, he has now " << _HitPoint << "HP left." << std::endl;  
    }    
}