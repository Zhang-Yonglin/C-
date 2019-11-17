#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//父类
class Parent
{
public:
	Parent(int a) {           //有参构造
		this->a = a;
	}

	virtual void func(int a)  //虚函数  一个参数
	{
		cout << "Parent::func(int)..." << endl;
	}

	virtual void func(int a, int b, int c)  //虚函数  三个参数
	{
		cout << "Parent::func(int ,int ,int )...." << endl;
	}
private:
	int a;
};


//子类
class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)            //有参构造
	{
		this->b = b;
	}
	virtual void func(int a)                  //虚函数重写  一个参数
	{
		cout << "Child: func(int)..." << endl;
	}

	void func(int a, int b) {                 //普通函数
		cout << "Child :func(int ,int )..." << endl;
	}

	virtual void func(int a, int b, int c)    //虚函数重写  三个参数
	{
		cout << "Child ::func(int ,int ,int )..." << endl;
	}
private:
	int b;
};


void myFunc(Parent *pp)  //传入的是父类指针
{
	pp->func(10);
}


int main(void)
{
	Parent *ppp = new Parent(10);
	Parent *cp = new Child(100, 200);         //父类指针可以指向子对象
	myFunc(ppp);
	myFunc(cp);
	
	cout << "--------------------" << endl;
	
	Parent *pp = new Child(100, 200);

	pp->func(10);//Parent ？ Child             //可以将父类中的函数func前面的virtual去掉做下测试
					          //如果调用一个普通函数，编译器根本就不会查找虚函数表。
					          //只有你调用的函数是虚函数的时候，才会去查找虚函数表
	pp->func(10, 20, 30);

	return 0;
}

//定义虚函数，会开辟虚函数表，存储虚函数的入口地址
//父类和子类都会开辟虚函数表
//如果说一个类有virtual虚函数关键字，在编译器给这个对象开辟空间的时候，会默认增加一个指针 vptr  指向虚函数表
//虚函数表是一个存储类成员函数指针的数据结构
//虚函数表是由编译器自动生成与维护的
//virtual成员函数会被编译器放入虚函数表中
//存在虚函数时，每个对象都有一个指向虚函数表的指针（vptr指针）
//不使用多态时，不需要使用虚函数，可以减少查找虚函数表的时间
