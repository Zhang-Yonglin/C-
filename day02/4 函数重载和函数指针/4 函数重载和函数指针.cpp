#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int func(int a, int b)
{
	cout << "func(int, int)" << endl;
	return 0;
}


int func(int a, int b, int c)
{
	cout << "func(int, int,int )" << endl;
	return 0;
}


//1 定义一种函数类型
typedef int(MY_FUNC)(int, int);

//2 定义一个指向函数类型的指针类型
typedef int(*MY_FUNC_P)(int, int);


int main(void)
{
	//1.
	MY_FUNC *fp = NULL;    //定义一个函数指针变量
	fp = func;             //函数名就是内存中存储函数代码的首地址
	fp(10, 20);


	//2.
	MY_FUNC_P fp1 = NULL;  //fp1为函数指针

	fp1 = func;
	fp1(10, 20);

	//3. 
	int(*fp3)(int, int) = NULL;
	fp3 = func;
	fp3(10, 20);

	func(10, 20);
	func(10, 20, 30);

	fp3 = func;           //fp3 ---> func(int,int)  即fp3指向func(int,int)函数

	//实际上在给函数指针赋值的时候，是会发生函数重载匹配的
	//在调用函数指针的时候，所调用的函数就已经固定了。
	int(*fp4)(int, int, int) = NULL;   //fp4为函数指针（且必须对应三个int参数）
	fp4 = func;                        //fp4 ---> func(int,int,int)  即fp4指向func(int,int,int函数


	fp3(10, 30);                       //func(int,int)
	fp3(10, 20);

	fp4(10, 30, 30);

	return 0;
}
