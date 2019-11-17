#include "Animal.h"


Animal::Animal()
{
	cout << "animal().." << endl;
}
Animal::~Animal()
{
	cout << "~Animal()..." << endl;
}


void letAnimalCry(Animal *animal)  //父类指针指向子对象
{
	animal->voice();

	if (animal != NULL) 
	{
		delete animal;
	}
}
