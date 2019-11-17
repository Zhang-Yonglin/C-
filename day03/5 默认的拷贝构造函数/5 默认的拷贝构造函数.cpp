#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class A
{
public:
#if 0
	A()    //默认的构造函数
	{
		
	}
#endif

#if 0
	A(const A &another)   //默认的拷贝构造函数
	{
		m_a = another.m_a;
		m_b = another.m_b;
	}
#endif

	A()              //自定义的无参构造函数
	{

	}
	A(int a, int b)  //定义的有参构造函数
	{

	}
	
#if 0
	~A()             //默认的析构函数
	{

	}
#endif
	~A()             //定义的析构函数
	{
		cout << "~A()" << endl;
	}
private:
	int m_a;
	int m_b;
};

//类中 会有个默认的无参构造函数：	、
//		-->当没有任何***显示的构造函数（显示的无参，显示有参，显示拷贝构造）*** 的时候，默认无参构造函数就会出现。

//		会有默认的拷贝构造函数：
//		-->当没有 **显示的拷贝构造 ***  的函数，默认的拷贝构造就会出现。

//     会有默认的析构函数
//      --> 当没有***显示的析构函数***的时候，  默认的析构函数就会出现。


int main(void)
{
	A a;
	A a1(a);  //调用默认的拷贝构造函数
	
	return 0;
}
