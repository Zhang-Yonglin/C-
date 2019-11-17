#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//c++语言对全局变量的定义检测能力增强了
int g_val;           //分配在bss段
//int g_val = 20;    //C++中不允许重定义

struct  student
{
	char name[64];
	int id;
};                  //注意要加分号


void test1()
{
	//定义一个变量 可以随用随定义  C语言中变量定义只能在程序的开始阶段  但在C++中，变量的定义最好也集中在程序的开始阶段，这样使得程序清晰且修改变量值也较为方便
	int i = 0;

	for (int i = 0; i < 10; i++)
	{

	}

	int b = 20;
	cout << "b " << b << endl;
}


void test2()
{
	student s1;   //若在C语言中一定需要加struct
	s1.id = 20;   //结构域赋值
}


int foo()             //C++函数必须有返回值类型
{
	return 10;
}


int g(int a)         //不可以传入多余参数   C语言中支持传入多余参数
{
	return 10;
}


//bool类型
void test3()
{
	//true 1  false 0  只能取这两个值
	bool flag = true;

	flag = false;

	flag = true;
	cout << "flag(true)" << flag << endl;
	flag = false;
	cout << "flag(true)" << flag << endl;
	flag = -20;
	cout << "flag(true)" << flag << endl;

	cout << sizeof(flag) << endl;
}

//三目运算符加强
void test4()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = (a < b) ? a : b;
	cout << c << endl;
	
	//三目运算符 可以当左值。
	((a < b) ? a : b) = 50;    // 返回的其实是变量的引用     //C语言中可以这样用： *(a < b ? a : b) = 50;
	//a = 50;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	#define A 20
	//const int f = 20;
}


//const增强
void test5()
{
	const int a = 10;         //a 是真正的常量    符号表概念  C语言中的常量是假的，可以被修改，而其他语言中的常量是真的

	int *p = (int*)&a;        //如果对一个常量取地址，编译器会临时开辟一个空间temp，让这个指针存放这个临时空间的地址

	*p = 20;                  //改变的是临时开辟的temp变量   

	cout << "a =" << a << endl;
	cout << "*p=" << *p << endl;

	int array[a] = { 0 };
	//cout << A << endl;
	//cout << 10 << endl;
	//cout << f << endl;
	
	// int *pp = &a;         //报错 因为a是常量，取地址时需要进行强制转换，如 int *p = (int*)&a;   
	
}


//枚举增强  每隔一段加一个分割
enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN
};


void test6()
{
	enum season s = AUT;

	if (s == AUT) {
	 cout << "s = AUT" << endl;

	}
}


int main(void)
{

	test2();
	cout << "------------------" << endl;
	test3();
	cout << "------------------" << endl;
	//g(10, 20, 30);
	cout << "------------------" << endl;
	test4();
	cout << "------------------" << endl;
	test5();
	cout << "------------------" << endl;
	test6();
	return 0;
}

/*
const int a 和 int const a，都表示a是一个常量，其值不能修改
const int *c（const int* c）表示指针指向的内存的值不可修改
int* const d 表示指针的指向不能更改，但指向的内存的值可以修改
const int * const e 表示二者均不可修改
*/
