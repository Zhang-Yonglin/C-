#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class A 
{
public:

	A(int a)  //有参构造
	{
		this->a = a;
	}

	void printA() {
		cout << "a = " << this->a << endl;
		//B objB(3000);
		//cout << objB.b << endl;
	}

	//声明一个友元类B  则此类可以被类B访问
	friend class B;
private:
	int a;
};


//友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）。当希望一个类可以存取另一个类的私有成员时，可以将该类声明为另一类的友元类。
class B
{
public:
	B(int b)
	{
		this->b = b;
	}
	void printB() {
		A objA(100);
		cout << objA.a << endl;            //如果不是友元类，则需要通过函数返回的方式进行访问变量a
		cout << "b = " << this->b << endl;
	}
	
	//friend class A;
private:
	int b;
};


int main(void)
{
	B bObj(200);

	bObj.printB();
	
	return 0;
}

