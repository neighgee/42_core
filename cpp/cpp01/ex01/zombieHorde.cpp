#include "Zombie.hpp"

Zombie*     zombieHorde(int N, std::string name)
{
    Zombie *horde; //array of zombies
    int i;

    if (N <= 0)
        return (NULL);
    horde = new Zombie[N];
    i = 0;
    while (i < N)
    {
        std::stringstream ss; //allows input(read) and output(write) operations
        ss << name << " " << i; //appends the number to ss
        horde[i].setName(ss.str());
        i++;
    }
    return (horde);
}