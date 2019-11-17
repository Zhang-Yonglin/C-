#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


class Test
{
public:
#if 0
	void init(int x, int y)  //变量的初始化  也可以实现构造函数的功能
	{
		m_x = x;
		m_y = y;
	}
#endif

	//test类的构造函数  无返回值 名称和类名相同  构造函数可以重载
	//在对象被创建的时候，用来初始化对象的函数
	Test()                //无参数的构造函数
	{
		m_x = 0;
		m_y = 0;
	}
	Test(int x, int y)    //有参构造
	{
		m_x = x;
		m_y = y;
		name = (char*)malloc(100);
		strcpy(name, "zhang3");
	}
	Test(int x)           //有参构造
	{
		m_x = x;
		m_y = 0;
	}

	void printT()         //打印变量函数
	{
		cout << "x = " << m_x << "  y = " << m_y << endl;
 	}

	//析构函数和构造函数都没有返回值
	//析构函数没有形参 无返回值
	~Test() {
		cout << "~Test()...." << endl;
		if (name != NULL) {
			free(name);    //释放指针name所指向的内存所存储的内容
			name = NULL;
			cout << "free succ!" << endl;
		}
	}
private:
	int m_x;
	int m_y;
	char *name;
};


//测试函数
void test1()
{
	Test t1(10, 20);
	t1.printT();

	//在一个对象临死之前，要调用析构函数
}


int main(void)
{
#if 0
	Test t1(10, 20);
	t1.printT();
	//t1.init(10, 20);

	Test t2(100);
	t2.printT();

	Test t3;          //就是调用类的无参数构造函数

	t3.printT();

#endif

	test1();
	
	return 0;
	
}

