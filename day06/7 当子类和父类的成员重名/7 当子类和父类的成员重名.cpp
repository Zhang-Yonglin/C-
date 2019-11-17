#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Parent
{
public:
	Parent(int a) {        //有参构造
		this->a = a;
	}
	
	int getA(){
		return a;
	}

	int a;
};


class Child :public Parent
{
public:
	Child(int p_a, int c_a) :Parent(p_a)
	{
		this->a = c_a;
	}

	void print()
	{
		cout << this->getA() << endl; //通过函数来访问
		cout << Parent::a << endl;    //通过类的域名来访问
		cout << this->a << endl;      //child's a
	}
	
	int a;
};


int main(void)
{
	Child c(10, 100);
	c.print();

	return 0;
}
