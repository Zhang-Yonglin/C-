#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//本程序会发生段错误

class Teacher
{
public:
	//构造函数
	Teacher(int id, const char *name)           //Teacher(int id, char *name) //这样写会有警告
	{
		cout << "Teacher (int ,char*).." << endl;

		//赋值id
		m_id = id;

		//赋值name
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);   //在堆上另分配内存 加1的原因是需要存储\0
		strcpy(m_name, name);
	}

	void printT()                              //打印函数
	{
		cout << "id = " << m_id << ", name = " << m_name << endl;
	}


	//析构函数  进行内存的释放
	~Teacher() {
		cout << "~Teacher（）。。。" << endl;
		if (m_name != NULL) 
　　　　　　　　　　　　　　　　{
			free(m_name);   //释放指针m_name所指向的内存所存储的内容
			m_name = NULL;  //m_name依然指向分配的那快内存，防止错误引用，需要将其值赋值为NULL
		}
	}
	
private:
	int m_id;
	char *m_name;  //会有警告
};


void test()
{
	Teacher t1(1, "zhang3");  
	t1.printT();

	Teacher t2(t1);         //t2 的默认拷贝构造
	t2.printT();

}


//主函数
int main(void)
{
	test();

	return 0;
}

//test执行完毕后，t2先析构，等到了t1进行析构时，所指向的内容已经被t2析构了，因此会发生段错误
//不明白可以再看看视频


