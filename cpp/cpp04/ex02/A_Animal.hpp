#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	protected:
		std::string type;

	public: //OCF format to guard against compiler generated shallow copies
	Animal();
	Animal (const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal(); //ensures that the child class is also deleted properly

	std::string getType() const;
	virtual void makeSound() const = 0; //pure virtual function, so no implementation

};

#endif
