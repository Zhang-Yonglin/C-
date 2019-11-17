#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//双目：两个参数

class Complex
{
public:
	Complex(int a, int b)  //有参构造函数
	{
		this->a = a;
		this->b = b;
	}

	void printComplex()    //打印函数
	{
		cout << "( " << this->a << ", " << this->b << "i )" << endl;
	}

	//friend Complex & operator+=(Complex &c1, Complex &c2);
	friend Complex &operator-=(Complex &c1, Complex &c2);  //友元函数   返回的是引用

	Complex &operator+=(Complex &another)                  //双目运算符重载
	{
		this->a += another.a;
		this->b += another.b;

		return *this;
	}
private:
	int a;     //实数
	int b;     //虚数
};


//全局
#if 0
Complex & operator+=(Complex &c1, Complex &c2) //返回引用
{
	c1.a += c2.a;
	c1.b += c2.b;

	return c1;
}
#endif

//全局函数
Complex &operator-=(Complex &c1, Complex &c2)   //返回引用
{
	c1.a -= c2.a;
	c1.b -= c2.b;

	return c1;
}


int main(void)
{
	Complex c1(1, 2);
	Complex c2(2, 4);

	(c1 += c2)+=c2;    //c1.operator+=(c2)  .operator(c2)

	c1.printComplex(); //c1发生改变
	c2.printComplex(); //c2没有改变

	cout << "--------" << endl;
	c1 -= c2;
	c1.printComplex();
	
	return 0;
}
