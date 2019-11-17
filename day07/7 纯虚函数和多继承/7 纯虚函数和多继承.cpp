#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//接口1
class Interface1
{
public:
	virtual void func1(int a, int b) = 0;  //纯虚函数
	virtual void func3(int a, int b) = 0;  //纯虚函数
};


//接口2
class Interface2
{
public:
	virtual void func2(int a) = 0;         //纯虚函数
};


//多继承
class Child :public Interface1, public Interface2
{
public:
	virtual void func1(int a, int b)       //虚函数重写
	{
		cout << "func1" << endl;
	}
	virtual void func3(int a, int b) {     //虚函数重写
		cout << "func3" << endl;

	}
	virtual void func2(int a)              //虚函数重写
	{
		cout << "func2 " << endl;
	}
};


int main(void)
{
	Interface1 *if1 = new Child;           //父亲指针指向子对象

	if1->func1(10, 20);
	if1->func3(100, 200);


	Interface2 *if2 = new Child;           //if2无法调用func1和func3

	if2->func2(10);

	return 0;
}
//构造函数是用来初始化的，因此不要在其中写其它的业务
