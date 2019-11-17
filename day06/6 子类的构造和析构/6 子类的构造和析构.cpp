#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Parent
{
public:
	Parent()          //无参构造
	{
		cout << "Parent().." << endl;
		a = 0;
	}
	Parent(int a) {   //有参构造
		cout << "Parent(int)..." << endl;
		this->a = a;
	}
	~Parent(){        //析构函数
		cout << "~Parent" << endl;
	}
	
	int a;
};


class Child :public Parent
{
public:
	// 在调用子类的构造函数时候，一定会调用父类的构造函数
	// 父类先构造，子类后构造。
	Child(int a, int b) :Parent(a)          //调用父类的有参构造
	{
		cout << "Child(int, int)..." << endl;
		this->b = b;
	}

	void printC() 
	{
		cout << "b = " << b << endl;
	}

	~Child(){
		cout << "~Child()..." << endl;  //先构造的后析构  后构造的先析构
	}

	int b;
};


int main(void)
{
	Child c(10, 20);

	c.printC();
	
	return 0;
}
