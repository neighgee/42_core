#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	protected:
		std::string type;

	public: //OCF format to guard against compiler generated shallow copies
	WrongAnimal();
	WrongAnimal (const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	~WrongAnimal(); //not virtual, will cause undefined behaviour
	std::string getType() const;
	void makeSound() const; //not virtual, will output the wrong sounds
};

#endif
