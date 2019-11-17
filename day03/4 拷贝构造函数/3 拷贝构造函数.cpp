#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//定义类
class Test
{
public:
	Test()              //无参构造函数
	{
		m_x = 0;
		m_y = 0;
	}
	Test(int x, int y)  //有参构造函数
	{
		m_x = x;
		m_y = y;
	}

	void printT()      //打印变量函数
	{
		cout << "x =" << m_x << ", y = " << m_y << endl;
	}

#if 1
	//显示的拷贝构造函数 如果不提供就会调用默认拷贝构造函数
	Test(const Test &another)  //引用另一个结构体对象，不能改变此结构体对象的值，所以加一个const将其保护起来
	{
		cout << "Test(const Test &)..." << endl;
		m_x = another.m_x;                        //同类之间无私处 可以直接访问private变量
		m_y = another.m_y;
	}
#endif

#if 0
	//会有一个默认的拷贝构造函数
	Test(const Test &another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}
#endif

	//= 赋值操作符
	void operator=(const Test &another)   //和显示拷贝构造函数的输入参数相同
	{
		m_x = another.m_x;
		m_y = another.m_y;
	}
	
private:
	int m_x;
	int m_y;
};


//拷贝构造函数就是将另一个同类型的类全部复制过来

int main(void)
{
	Test t1(100, 200); 
	Test t2(t1);       //通过t1给t2赋值（初始化）  
	//Test t3=t1       //依然是初始化t3的时候调用t3构造函数，依然是调用t3的拷贝构造函数（= 赋值操作符）
	t2.printT();   
	
	cout << "------------" << endl;
	
	//构造函数是对象初始化的时候调用
	Test t3;          //初始化，调用无参构造
	t3.printT(); 
	t3 = t1;          //调用的不是t3拷贝构造函数，而是t3的赋值操作符函数
	t3.printT(); 

	return 0;
}
