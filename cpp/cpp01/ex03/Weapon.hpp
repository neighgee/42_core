#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
    private:
            std::string _type;

    public:
            Weapon(std::string type);
            const std::string &getType(void) const; //2nd const shows that it just reads
            void setType(std::string type);
};

#endif