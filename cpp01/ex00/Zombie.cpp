#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    if (name.empty())
        this->_name = "name ";
    else
        this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << "has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}