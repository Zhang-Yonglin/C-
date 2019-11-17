#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

//面向对象
class Dog
{
public:
	void eat(char *food)
	{
		cout << name << "吃" << food << endl;
	}

	char name[64];
};


//面向过程
void eat(class Dog &dog, char *food)  //类的引用
{
	cout << dog.name << "吃" << food << endl;
}


int main(void)
{
	Dog dog;
	strcpy(dog.name, "狗");
	dog.eat("翔");
	
	eat(dog, "翔");
	

	return 0;
}
