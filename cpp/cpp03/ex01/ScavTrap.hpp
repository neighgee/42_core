#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //public members let public members stay public & protected members stay protected, aka everything is default
{
	public:
	ScavTrap(std::string name);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate(void);
};

#endif
