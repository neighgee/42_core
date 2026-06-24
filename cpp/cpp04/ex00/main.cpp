#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout <<"----DEFAULT SUBJECT.TXT MAIN----" << std::endl;
	std::cout << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound(); //will output the dog sound! (WOOF)
	i->makeSound(); //will output the cat sound! (MEOW)
	meta->makeSound(); //will output the animal sound! (BOOM)
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout <<"----NON-DEFAULT TESTS BY MOA----" << std::endl;
	std::cout << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << std::endl;
	wrongmeta->makeSound(); //normal animal sound
	wrongcat->makeSound(); //output sound same as animal, no meow
	delete wrongmeta;
	delete wrongcat; // will not delete wrongcat, only wronganimal
	return (0);
}
