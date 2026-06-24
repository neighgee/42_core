#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type; //"this" only applies to nonstatic member functions
}

const std::string& Weapon::getType(void) const
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type; //"this" only applies to nonstatic member functions
}