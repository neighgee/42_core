#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected: //ClapTrap and its children classes can access the attributes
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

	public:
	ClapTrap(std::string name);
	~ClapTrap();

	void attack(const std::string& target); //attack takes in the reference of target
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
