#include "Zombie.hpp"

int main (void)
{
    Zombie *zombie1;
    Zombie *zombie2;

    zombie1 = newZombie("");
    zombie1->announce();
    delete zombie1;

    zombie2 = newZombie("Heap Zombie");
    zombie2->announce();
    delete zombie2; 

    randomChump("Stack Zombie");
    return (0);
}