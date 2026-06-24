#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap A("Alpha");
	ScavTrap B("Scav_B");

	std::cout << std::endl;
	A.attack("Dummy 1");
	A.takeDamage(3);
	A.beRepaired(2);

	std::cout << std::endl;
	B.takeDamage(30);
	B.beRepaired(5);
	B.attack("Dummy 2");
	B.guardGate();

	std::cout << std::endl;
	return (0);
}
