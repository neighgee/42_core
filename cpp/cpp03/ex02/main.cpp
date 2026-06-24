#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap A("Alpha");
	ScavTrap B("S");
	FragTrap C("Ribbity");

	std::cout << std::endl;
	A.attack("Dummy 1");
	A.takeDamage(3);
	A.beRepaired(2);

	std::cout << std::endl;
	B.takeDamage(30);
	B.beRepaired(5);
	B.attack("Dummy 2"); //initialised with attackDamage of 20
	B.guardGate();

	std::cout << std::endl;
	C.takeDamage(30);
	C.beRepaired(5);
	C.attack("Dummy 3"); //initialised with attackDamage of 30
	C.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
