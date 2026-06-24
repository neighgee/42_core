#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap //public members let public members stay public & protected members stay protected, aka everything is default
{
	public:
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);
};

#endif
