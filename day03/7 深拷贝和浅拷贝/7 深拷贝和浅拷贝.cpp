#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class Teacher
{
public:

	//析构函数
	Teacher(int id, const char *name)               //Teacher(int id, char *name) //这样写会有警告
	{
		cout << "Teacher (int ,char*).." << endl;

		//赋值id
		m_id = id;

		//赋值name
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);        //在堆上另分配内存 加1的原因是需要存储\0
		strcpy(m_name, name);
	}

	void printT()    //打印函数
	{
		cout << "id = " << m_id << ", name = " << m_name << endl;
	}


	//显示的提供一个拷贝构造函数，来完成深拷贝动作
	Teacher(const Teacher &another)
	{
		m_id = another.m_id;
		
		//深拷贝动作
		int len = strlen(another.m_name);
		m_name = (char*)malloc(len + 1);         //在堆上分配内存
		strcpy(m_name, another.m_name);
	}

	
	//析构函数  进行内存的释放
	~Teacher() {
		cout << "~Teacher（）。。。" << endl;
		if (m_name != NULL) 
                {
			free(m_name);                    //释放指针m_name所指向的内存所存储的内容
			m_name = NULL;                   //m_name依然指向分配的那快内存，防止错误引用(野指针)，需要将其值赋值为NULL
		}
	}
	
private:
	int m_id;
	char *m_name;                                    //会有警告
};


//测试函数
void test()
{
	Teacher t1(1, "zhang3");  
	t1.printT();

	Teacher t2(t1);                                  
        //t2 拷贝构造（深拷贝） 如果不是深拷贝，两个m_name指向同一个堆区，在函数执行完毕后，t1先释放，到t2释放时，会发生段错误
	t2.printT();

}


//主函数
int main(void)
{
	test();

	return 0;
}

/*
char *背后的含义是：给我个字符串，我要修改它。而理论上，我们传给函数的字面常量是没法被修改的。
所以说，比较和理的办法是把参数类型修改为const char *。这个类型说背后的含义是：给我个字符串，我只要读取它。
*/


