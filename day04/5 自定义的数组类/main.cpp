#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MyArray.h"

using namespace std;


int main(void)
{

	MyArray array1(10);                 //开辟10元素的数组

	//赋值操作
	for (int i = 0; i < 10; i++) 
	{
		array1.setData(i, i + 10);  //i是索引，i+10是数值
	}

	cout << "----------" << endl;

	//打印操作
	cout << "array1:" << endl;
	for (int i = 0; i < 10; i++) 
	{
		cout << array1.getData(i) << " ";
	}
	cout << endl;


	cout << "----------" << endl;
	MyArray array2 = array1;           //调用拷贝构造函数  初始化时调用的都是构造函数（无参构造函数、有参构造函数、拷贝构造函数）
	cout << "array2:" << endl;
	for (int i = 0; i < array2.getLen(); i++) 
	{
		cout << array2.getData(i) << " ";
	}
	cout << endl;
	
	
	cout << "----------" << endl;
	MyArray array3;                   //调用无参构造函数
	array3 = array1;                  //调用=操作符，因为只能初始化一次，所以不能调用构造函数了，需要使用=操作符

	cout << "array3:" << endl;
	for (int i = 0; i < array3.getLen(); i++) 
	{
		cout << array3.getData(i) << " ";
	}
	cout << endl;
	cout << "程序运行结束，析构函数调用：" << endl;

	return 0;
}
