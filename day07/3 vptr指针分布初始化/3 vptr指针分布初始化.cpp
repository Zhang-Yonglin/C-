#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)          //有参构造
	{
		cout << "Parent(int ..)" << endl;
		this->a = a;

		print();       //是调用父类的print（） 还是 子类的print（）？
			       //通过结果 此时调用的父类的print 并不是子类的print
	}

	virtual void print()   //虚函数
	{
		cout << "Parent::print()...a = "<<a << endl;
	}
private:
	int a;
};


class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)   //在调用父类的构造器的时候，会将vptr指针当做父类来处理。   vptr是分布初始化的
				         //此时会临时指向父类的虚函数表
	{
		//将子类对象的空间有编程子类对象处理，vptr指针就从指向父类的表 变成 指向子类的表

		cout << "Child (int ,int )" << endl;
		this->b = b;
		print();                 //此时vptr指针已经回到了 子类的表， 调用的是子类的print函数。

	}

	virtual void print() {           //虚函数重定义
		cout << "Child ::Print()..b = " << b << endl;
	}
private:
	int b;
};


int main(void)
{
	Parent *pp = new Child(10, 20);
	pp->print();                    //发生多态  调用子类中的重写的方法

	cout << "-------------------------" << endl;
	
	delete pp;
	
	return 0;
}

//构造子类的时候，会默认首先构造父类（如果父类没有显示构造函数，则首先调用默认构造函数）
