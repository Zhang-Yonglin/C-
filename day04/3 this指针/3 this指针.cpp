#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Test
{
public:
	Test(int k)                    //有参构造
	{
		this->m_k = k;
	}
	
	int getK()  const             //成员函数尾部出现const 修饰的是this指针 加上this指针后对象的内容就无法修改
	{
		//this->m_k = 100;    //this指针不是 const Test *  其指向内容可以修改（即指向的类的对象可以改变）
		//this++;             //this指针是一个常指针， Test *const  
		//this->m_k = 100;
		//this = this + 1;
		return this->m_k;
	}

	//static成员函数，只能返回static成员变量
	static int s_getK()
	{
		//return m_k;
		return s_k;
	}
private:
	int m_k;
	static int s_k;
};


int Test::s_k = 0;


int main(void)
{
	Test t1(10); //Test(&t1, 10);
	Test t2(20);


	return 0;
}

//静态成员函数只能访问静态数据成员。原因：非静态成员函数，在调用时this指针被当作参数传进
//而静态成员函数属于类，而不属于对象，没有this指针。
