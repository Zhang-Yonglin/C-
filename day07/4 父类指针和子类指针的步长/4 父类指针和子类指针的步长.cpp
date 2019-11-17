#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)             //有参构造
	{
		this->a = a;
	}
	virtual void print()      //虚函数  虚函数最关键的特点是“动态联编”，它可以在运行时判断指针指向的对象，并自动调用相应的函数。
	{
		cout << "Parent::print a=  " << a << endl;
	}
	int a;
};


class Child :public Parent
{
public:
	Child(int a) :Parent(a)  //有参构造
	{

	}
	virtual void print()     //虚函数  进行函数体的重新定义
	{
		cout << "Child::print a=  " << a << endl;
	}
	int b;
};


int main(void)
{
	Child array[] = { Child(0), Child(1), Child(2) };  //每个数组元素都是类的对象
	
	Parent *pp = &array[0];                            //父类指针指向子对象
	Child *cp = &array[0];

	pp++;

	pp->print();
	cp->print();
	
	cout << "-----" << endl;

#if 1
	pp++;    //pp +sizeof(Parent)
	cp++;    //cp +sizeof(Child)

	pp->print();
	cp->print();
#endif
	cout << "-----" << endl;

	int i = 0;
	for (cp= &array[0], i = 0; i < 3; i++, cp++) {   //cp是子类的指针  如果cp改为pp，则会出错。因为子类中比父类元素多，指针都加1后表示的地址就不一样了(偏移错误)。故不能通过一个父类指针去索引一个子类对象
		cp->print();                
	}

	return 0;
}
