#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Test
{
public:
	Test(int a, int b)       //有参构造函数
	{
		this->a = a;
		this->b = b;
	}

	void printT()            //打印函数
	{
		cout << "a = " << this->a << ", b=" << this->b << endl;
	}

	int getA()
	{
		return this->a;  //使用this指针的好处：如果类中有很多变量，则使用this可以知道哪些是成员变量
	}

	int getB()
	{
		return this->b;
	}

	//成员方法
	Test TestAdd(Test &another)
	{
		Test temp(this->a + another.a,this->b + another.b);  //同类之间无私处

		return temp;
	}

	//+= 方法
	Test& TestAdd2(Test &another)  //引用传递  返回引用
	{
		this->a += another.a;
		this->b += another.b;

		//this===>&t1
			
		return *this;          //如果想返回一个对象的本身，在成员方法中，用*this返回
	}

private:
	int a;
	int b;
};


//1 在全局提供一个两个Test相加的函数
Test TestAdd(Test &t1, Test &t2)       //引用传递
{
	Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());

	return temp;
}


int main(void)
{
	Test t1(10, 20);
	Test t2(100, 200);

	//使用全局函数实现相加
	Test t3 = TestAdd(t1, t2);
	t3.printT();
	
	cout << "--------------------" << endl;
	
	//使用成员函数实现相加
	Test t4 = t1.TestAdd(t2);
	t4.printT();


	//((t1 += t2) += t2 )+= t2

	//如果相对一个对象连续调用成员方法，每次都会改变对象本身，成员方法需要返回引用
	t1.TestAdd2(t2).TestAdd2(t2);
	t1.printT();

	return 0;
}
