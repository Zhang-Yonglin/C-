#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//这个代码的视频关于delete和free的区别讲的很好

using namespace std;

//new和delete是在堆上创建内存和删除内存存储的内容


class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
		m_a = 0;
		m_b = 0;
	}

	Test(int a, int b)
	{
		cout << "Test(int, int)" << endl;
		m_a = a;
		m_b = b;
	}

	void printT()
	{

		cout << "printT:"<< m_a << "," << m_b << endl;
	}

	~Test()
	{
		cout << "~Test()" << endl;

	}

private:
	int m_a;
	int m_b;
};


//C语言中
void test1()
{
	//给变量分配内存
	int *p = (int *)malloc(sizeof(int));

	*p = 10;
	if (p != NULL) 
       {
		free(p);
		//delete p;   //malloc创建的空间可以用delete释放
		p = NULL;
	}


	//给数组分配内存
	int *array_p = (int *)malloc(sizeof(int)* 10);

	for (int i = 0; i < 10; i++) 
        {
		array_p[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) 
        {
		printf("%d ", array_p[i]);
	}

	printf("\n");

	//释放数组指针
	if (array_p != NULL) 
        {
		free(array_p);
		array_p = NULL;
	}

	cout << "==========" << endl;

	Test *tp = (Test*)malloc(sizeof(Test));
	tp->printT();       //打印会乱码，因为没有初始化

	if (tp != NULL) 
	{
		free(tp);   //释放指针tp指向的内存存储的内容
		tp = NULL;  //将指针tp指向空
	}
}


//malloc free 是函数，标准库，stdlib.h
//new 在堆上初始化一个对象的时候，会触发对象的构造函数。malloc不能
//free并不能触发一个对象的析构函数
//C++中
void test2()
{
	int *p = new int;
	*p = 10;
	if (p != NULL) 
        {
		free(p);                 //new创建的空间也可以用free释放
		p = NULL;
	}

	int *array_p = new int[10];
	for (int i = 0; i < 10; i++) 
	{
		array_p[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) 
	{
		cout << array_p[i]<<" ";
	}
	cout << endl;

	if (array_p != NULL) 
	{
		delete [] array_p;
	}

	cout << "==========" << endl;
	//Test *tp = new Test(10, 20);  //触发有参构造
	Test *tp = new Test;            //触发无参构造  C语言中的malloc无法触发构造函数，只能手动写初始化函数进行初始化函数
	tp->printT();
	if (tp != NULL) 
	{
		delete tp;
		tp = NULL;
	}

}


int main(void)
{
	test1();

	cout << "-----------" << endl;

	test2();
	
	return 0;
}
