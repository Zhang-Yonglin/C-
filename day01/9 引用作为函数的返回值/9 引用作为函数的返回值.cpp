#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>


using namespace std;


//返回指针
char * getmem(int num)
{
	char *p = NULL;
	p = (char*)malloc(num);

	return p; //ox11223344
} //0x1231321


int getmem2(char **pp, int num)
{
	char *p = NULL;
	p = (char*)malloc(num);

	*pp = p;

	return 0;
} //0


int getA1()
{
	int a = 10;

	return a;
} //a的值  有拷贝动作 若返回的是结构体或者数组，则拷贝动作消耗较多时间


void getA2(int *a)
{
	*a = 10;                  //通过地址修改变量
}


//引用作为返回值，不要返回局部变量的引用
int& getA3()                      //返回值是一个引用
{
	int a = 10;
	return a;
}//int &temp = a;


int &getA4()
{
	static int a = 10;       //静态变量

	return a;
}


int main(void)
{
	int a = 0;
	char *pp = NULL;

	a = getA1();
	pp = getmem(10);

	cout << "-------------------------" << endl;

	int main_a = 0;

	//main_a = getA3(); //main_a = temp; //数值拷贝

	cout << "main_a " << main_a << endl;

	cout << "-------------------------" << endl;

#if 0	
	int &main_a_re = getA3(); 

	cout << "main_a_re " << main_a_re << endl;  //main_a_re本质上是一个指针，函数调用结束后其中的变量被释放，main_a_re指向内存被释放，因此会发生段错误
	cout << "main_a_re " << main_a_re << endl;
#endif

	int &main_a_re = getA4();                   //函数的返回是引用，则需要用引用变量来接收   同理，如果函数返回的是指针，则需要用指针变量来接收
	cout << "main_a_re " << main_a_re << endl;
	cout << "main_a_re " << main_a_re << endl;

	//引用如果当函数返回值的话，函数可以当左值
	getA4() = 1000;

	return 0;
}
