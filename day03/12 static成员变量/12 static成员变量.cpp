#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class AA
{
public:
	AA(int a, int b)         //构造函数
	{
		m_a = a;
		m_b = b;
	}

	int getC()              //获取类中变量值
	{
		m_c++;
		return m_c;
	}
	
	//静态的成员方法
	static int& getCC()     //引用
	{
		return m_c;
	}

private:
	int m_a;
	int m_b;
	//static修饰的静态成员变量 
	static int m_c;
	
};


//静态成员变量的初始化，一定在类的外边。  静态成员变量存储在静态区  如果将静态成员变量放在public中，则可以直接访问：AA::m_c   
int AA::m_c = 100;   //前面要加上数据类型

static void test()   //使用static修饰的函数只能在这个文件中使用，即作用域只能在此文件中 
{

}


void test1()
{
	static int a = 10;
	a++;
	cout << a << endl;
	return;
}


int main(void)
{
	AA a1(10, 20);
	AA a2(100, 200);

	cout << a1.getC() << endl;//101
	cout << a2.getC() << endl;//102

	//a1.getCC() = 200;   //可以这样调用
	AA::getCC() = 200;    //可以这样调用，返回引用，因为静态成员变量属于整个类任意一个类的实例都可以进行访问

	cout << a1.getC() << endl;//201
	cout << a2.getC() << endl;//202
	
	test();
	test();

	return 0;
}
