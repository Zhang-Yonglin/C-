#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;


int main(void)
{
	letAnimalCry(new Dog);

	letAnimalCry(new Cat);
	
	cout << "--------------" << endl;

#if 1
	Animal *dog = new Dog;
	letAnimalCry(dog);
	//delete dog;     //加上此句代码会发生段错误，因为dog在函数letAnimalCry中已经被析构函数所释放
#endif

	return 0;
}
