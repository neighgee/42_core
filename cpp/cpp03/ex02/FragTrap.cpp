#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name) //ClapTrap(name) calls ClapTrap constructor then ScavTrap constructor
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " is constructed~" << std::endl;
}

FragTrap::~FragTrap() //no need to call ClapTrap destructor, it calls it automatically after ScavTrap
{
	std::cout << "FragTrap " << this->_name << " is destroyed!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout <<"FragTrap " << this->_name << " requests for a positive high five" << std::endl;
}
