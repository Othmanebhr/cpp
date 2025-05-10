#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("init"), _HitPoint(10), _EnergyPoint(10), _AttackDammage(0) {}

ClapTrap::ClapTrap(std::string name) : _name(name) {}

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
    *this = cpy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{

}