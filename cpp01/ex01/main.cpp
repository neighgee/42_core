#include "Zombie.hpp"

int main (void)
{
    Zombie *horde;
    int i;
    int N;

    N = 10;
    horde = zombieHorde(N, "Horde Zombie");
    if (!horde)
        return (1);
    i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde; //cannot just use delete, delete only for single object
    return (0);
}