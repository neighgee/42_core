#include "Dog.hpp"

Dog::Dog()
 {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
 }

Dog::Dog(const Dog& other) : Animal(other)
 {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
 }

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	if (this->brain)
		delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "WOOF!" << std::endl;
}

void Dog::setideas(int index, const std::string& idea)
{
	this->brain->setideas(index, idea);
}

std::string Dog:: getideas(int index) const
{
	return(this->brain->getideas(index));
}
