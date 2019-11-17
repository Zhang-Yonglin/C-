#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

//宏函数（无需数据类型，预处理器处理）
#define MAX(a, b) \              
	((a)>(b)?(a):(b))       
 //每个变量都加上括号，防止操作混乱

//取两个数的较大值
int max(int a, int b)
{
	return (a > b) ? a : b;
}


//函数声明
inline void printAB(int a, int b);       //函数较为简单且频繁使用，则可以定义为内联函数（编译器处理）


int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = MAX(a++, b++);               //宏函数可以解决压栈出栈的弊端，但是无法解决传参弊端（宏函数只是简单的文本替换）
	cout << "a=" << a;
	cout << "b=" << b;
	cout <<"c = " <<c<<endl;
#if 1                                    //if 后面的1改为0,则其中的代码不运行
	for (int i = 0; i < 1000; i++) {
		a++;
		b++;
		printAB(a++, b++);
	}
#endif
	return 0;
	
}


//打印出两个变量的值
inline void printAB(int a, int b)
{
	cout << "a = " << a << ", b = " << b << endl;
}
