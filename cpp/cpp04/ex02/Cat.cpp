#include "Cat.hpp"

Cat::Cat()
 {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
 }

Cat::Cat(const Cat& other) : Animal(other)
 {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
 }

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	if (this->brain)
		delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}

void Cat::setideas(int index, const std::string& idea)
{
	this->brain->setideas(index, idea);
}

std::string Cat:: getideas(int index) const
{
	return(this->brain->getideas(index));
}
