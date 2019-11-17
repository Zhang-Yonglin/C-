#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Parent
{
public:
	virtual void func()       //虚函数
	{
		cout << "Parent::func().." << endl;
	}
	/*
	virtual void func(int a)  //虚函数  //函数重载
	{
		cout << "Parent::func().." << endl;
	}
	*/
private:
	int a;
};


class Parent2
{
public:
	void func()
	{
		cout << "Parent2::func().." << endl;
	}
private:
	int a;
};


int main(void)
{
	Parent p1;
	Parent2 p2;

	cout << "sizeof(p1) " << sizeof(p1) << endl;  //多出来的4个字节就是vptr指针所占用的空间。
	cout << "sizeof(p2) " << sizeof(p2) << endl;

	return 0;
}
//只要有虚函数，就会出现vptr指针，多个虚函数时，还是一个vptr指针，并不会增多
