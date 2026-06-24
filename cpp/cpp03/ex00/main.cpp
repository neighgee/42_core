#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("Alpha");
	A.attack("Dummy 1"); //attackDamage started at 0
	A.takeDamage(3);
	A.beRepaired(2);

	std::cout << std::endl;
	ClapTrap B("Beta"); //attackDamage started at 0
	for (int i = 0; i < 11; i++)
		B.attack("Dummy 2"); //can only attack 10 times

	std::cout << std::endl;
	return (0);
}
