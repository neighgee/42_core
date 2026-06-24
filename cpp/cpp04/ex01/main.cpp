#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout <<"----DEFAULT SUBJECT.TXT MAIN----" << std::endl;
	std::cout << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout <<"----NON-DEFAULT TESTS BY ME----" << std::endl;
	std::cout << std::endl;

	std::cout <<"----Array Tests Required by Subject.txt----" << std::endl;
	std::cout << std::endl;
	const int size = 10; // can change number of animals
	Animal* animals[size];
	for (int index = 0; index < size; index++)
	{
		if (index % 2 == 0)
			animals[index] = new Dog();
		else
			animals[index] = new Cat();
		std::cout << std::endl;
	}
	for (int index = 0; index < size; index++)
	{
		std::cout <<animals[index]->getType()<< ": ";
		animals[index]->makeSound();
		std::cout << std::endl;
	}
	for (int index = 0; index < size; index++)
	{
		delete animals[index];
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout <<"----Deep Copy Test: Dog Copy Constructor----" << std::endl;
	std::cout << std::endl;
	Dog old_dog;
	old_dog.setideas(0, "I wanna eat bones");
	Dog copy_dog(old_dog); // calls copy constructor
	std::cout << std::endl;
	std::cout << "Original idea before change: " << old_dog.getideas(0) << std::endl;
	std::cout << "Copy idea before change: " << copy_dog.getideas(0) << std::endl;
	old_dog.setideas(0, "I wanna eat treats");
	std::cout << "Original idea after change: " << old_dog.getideas(0) << std::endl;
	std::cout << "Copy idea after change: " << copy_dog.getideas(0) << std::endl; //needs to be different to ensure deep copy

	std::cout << std::endl;

	std::cout <<"----Deep Copy Test: Dog Copy Assignment Operator----" << std::endl;
	std::cout << std::endl;
	Dog dogA;
	dogA.setideas(0, "I wanna bark");
	Dog dogB;
	std::cout << std::endl;
	dogB = dogA; //calls copy assignment operator
	std::cout << std::endl;
	std::cout << "Original idea before change: " << dogA.getideas(0) << std::endl;
	std::cout << "Copy idea before change: " << dogB.getideas(0) << std::endl;
	dogA.setideas(0, "I wanna go for a walk");
	std::cout << "Original idea after change: " << dogA.getideas(0) << std::endl;
	std::cout << "Copy idea after change: " << dogB.getideas(0) << std::endl; //needs to be different to ensure deep copy

	std::cout << std::endl;

	std::cout <<"----Deep Copy Test: Cat Copy Constructor----" << std::endl;
	std::cout << std::endl;
	Cat old_cat;
	old_cat.setideas(0, "I wanna eat fish");
	std::cout << std::endl;
	Cat copy_cat(old_cat); // calls copy constructor
	std::cout << std::endl;
	std::cout << "Original idea before change: " << old_cat.getideas(0) << std::endl;
	std::cout << "Copy idea before change: " << copy_cat.getideas(0) << std::endl;
	old_cat.setideas(0, "I wanna eat catnip");
	std::cout << "Original idea after change: " << old_cat.getideas(0) << std::endl;
	std::cout << "Copy idea after change: " << copy_cat.getideas(0) << std::endl; //needs to be different to ensure deep copy

	std::cout << std::endl;

	std::cout <<"----Deep Copy Test: Cat Copy Assignment Operator----" << std::endl;
	std::cout << std::endl;
	Cat catA;
	catA.setideas(0, "I wanna meow");
	Cat catB;
	std::cout << std::endl;
	catB = catA; //calls copy assignment operator
	std::cout << std::endl;
	std::cout << "Original idea before change: " << catA.getideas(0) << std::endl;
	std::cout << "Copy idea before change: " << catB.getideas(0) << std::endl;
	catA.setideas(0, "I wanna take a catnap");
	std::cout << "Original idea after change: " << catA.getideas(0) << std::endl;
	std::cout << "Copy idea after change: " << catB.getideas(0) << std::endl; //needs to be different to ensure deep copy

	std::cout << std::endl;
	return (0);
}
