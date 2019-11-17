#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;


class A
{
public:
	A() {                                  //无参构造
		cout << "A()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);        //初始化为0
		strcpy(this->p, "A String..");
	}

	virtual void print()                   //虚函数
	{
		cout << "A: " << this->p << endl;
	}

	virtual ~A() {
		cout << "~A()..." << endl;
		if (this->p != NULL) 
		{
			delete[]this->p;
			this->p = NULL;
		}
	}
private:
	char *p;
};


class B :public A
{
public:
	B() //此刻会触发A()，则A中构造会分配内存，在析构时也需要进行释放，所以将析构函数写成虚函数，既析构A，又析构B，从而防止内存泄漏。（否则只会调用A中的析构）
	{
		cout << "B()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "B String..");
	}

	virtual void print()  //重写虚函数
	{
		cout << "B: " << this->p << endl;
	}

	virtual ~B() {                      //发生多态，先析构B，再析构A(构造时：先构造A，再构造B)
		cout << "~B()..." << endl;
		if (this->p != NULL) 
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char *p;
};


void func(A *ap)
{
	ap->print();  //在此发生多态

}


void deleteFunc(A *ap)
{
	delete ap;   //此刻ap->~B() //~B() ---> ~A()   触发析构B，会默认析构A   构造时是先构造A，再构造B，则析构时应该先析构B，再析构A
}


void test()
{
	A *ap = new A;
	func(ap);
	B *bp = new B;
	func(bp);

	deleteFunc(bp);
}


//主函数
int main(void)
{
	test();
	
	cout << "------------" << endl;
	B bObj;

	return 0;
}

//重载  重写  重定义
//1 重载 一定是同一个作用域下
//2 重定义： 是发生在两个不同的类中，一个是父类，一个是子类
//         1,普通函数重定义 如果父类的普通成员函数被子类重写，是重定义
//         2,虚函数重写    如果父类的虚函数被子类重写，就是虚函数重写，这个函数会发生多态
//为何要给父类的虚函数加上virtual关键字。  使得发生多态 让父类指针指向子类对象的时候能够调用子类的方法而不是父类的方法 让其做动态联编 选择调用父类方法还是子类方法  和虚继承的关键字无关
