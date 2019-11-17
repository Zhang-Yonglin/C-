#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Complex
{
public:
	Complex(int a, int b)  //有参构造函数
	{
		this->a = a;
		this->b = b;
	}

	void printComplex()   //打印函数
	{
		cout << "( " << this->a << ", " << this->b << "i )" << endl;
	}

	//friend Complex & operator++(Complex &c);
	//friend const Complex operator++(Complex &c1, int);

	//前++
	Complex &operator++()  //成员方法  不用写参数
	{
		this->a++;
		this->b++;

		return *this;
	}

	//后++
	const Complex operator++(int)    //亚元  后++时会自动找到带有亚元的成员函数进行操作
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;
	}


private:
	int a;//实数
	int b;//虚数
};


#if 0
//重载的是前++运算符
Complex & operator++(Complex &c)
{
	c.a++;
	c.b++;
	return c;
}
#endif


//重载的是后++运算符
#if 0
const Complex operator++(Complex &c1, int)  //int 表示占位符
{
	Complex temp(c1.a, c1.b);           //临时变量

	c1.a++;
	c1.b++;

	return temp;
}
#endif


int main(void)
{
	Complex c1(1, 2);

	//++++c1;

	c1++;

	c1.printComplex();

	//++++c1;

	return 0;
}
