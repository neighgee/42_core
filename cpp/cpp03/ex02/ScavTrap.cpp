#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name) //ClapTrap(name) calls ClapTrap constructor then ScavTrap constructor
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " is constructed~" << std::endl;
}

ScavTrap::~ScavTrap() //no need to call ClapTrap destructor, it calls it automatically after ScavTrap
{
	std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no more hit points!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no more energy points!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " and causes " << this->_attackDamage << " points of damage!" << std::endl;

}

void ScavTrap::guardGate(void)
{
	std::cout <<"ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
