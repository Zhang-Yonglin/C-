#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//操作符重载：给操作符一个新的含义

class Complex
{
public:
	Complex(int a, int b)   //有参构造函数
	{
		this->a = a;
		this->b = b;
	}

	void printComplex()    //打印函数
	{
		cout << "( " << this->a << ", " << this->b << "i )" << endl;
	}

	friend Complex complexAdd(Complex &c1, Complex &c2);   //定义友元函数  返回类型为类
	//friend Complex operator+(Complex &c1, Complex &c2);
	//friend Complex  operator-(Complex &c1, Complex &c2);

	Complex complexAdd(Complex &another)   //成员方法
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	Complex operator+(Complex &another)    // + 操作符重载
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
	
	Complex operator-(Complex &another)    // - 操作符重载
	{
		Complex temp(this->a - another.a, this->b - another.b);
		return temp;
	}

private:
	int a;   //实数
	int b;   //虚数
};


//全局函数方式
Complex complexAdd(Complex &c1, Complex &c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

//操作符重载写在全局
#if 0
Complex operator+(Complex &c1, Complex &c2)     //operator+构成一个函数名
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

Complex operator-(Complex &c1, Complex &c2)
{
	Complex temp(c1.a - c2.a, c1.b - c2.b);
	return temp;
}

#endif


int main(void)
{
	Complex c1(1, 2);
	Complex c2(2, 4);

	c1.printComplex();
	c2.printComplex();
	cout << "-----------------" << endl;
	
	//全局方法调用
	Complex c3 = complexAdd(c1, c2);
	c3.printComplex();
	cout << "-----------------" << endl;
	
	//成员方法调用
	Complex c4 = c1.complexAdd(c2);
	c4.printComplex();
	cout << "-----------------" << endl;
	
	//操作符重载（全局）
	//Complex c5 = c1 + c2;   //等价于Complex c5 = operator+(c1, c2);

	//操作符重载（成员方法）
	Complex c6 = c1.operator+(c2);  //
	c6.printComplex();
	cout << "-----------------" << endl;
	
	Complex c7 = c1 + c2;
	c7.printComplex();
	cout << "-----------------" << endl;
	
	Complex c8 = c1 - c2 - c1;     //可以进行连减，但是如果成员函数Complex operator-(Complex &another)返回的是一个引用，则不能进行连减
	c8.printComplex();	       //c1-c2返回的是匿名对象，创建临时的局部变量，返回给匿名对象，匿名对象再和c1相减，再返回给一个匿名对象并将其返给c8。但是如果函数返回的是引用，则不能连减，
				       //因为返回的是别名，c1-c2结束后temp被回收，返回的则是乱码
	cout << "-----------------" << endl;

	return 0;
	
}
