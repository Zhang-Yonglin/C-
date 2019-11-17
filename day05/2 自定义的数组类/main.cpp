#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MyArray.h"

using namespace std;


int main(void)
{
 	MyArray array1(10);      //开辟10元素的数组

	//赋值操作
	for (int i = 0; i < 10; i++) 
	{
		//array1.setData(i, i + 10);
		array1[i] = i + 10;//space[1] = 1+10
	}

	cout << "--------" << endl;

	cout << "array1:" << endl;
	for (int i = 0; i < 10; i++) 
	{
		cout << array1[i] << " ";  //[]操作符重载
	}
	cout << endl;


	MyArray array2 = array1;
	cout << "array2:" << endl;
	for (int i = 0; i < array2.getLen(); i++) 
	{
		cout << array2[i] << " ";
	}
	cout << endl;

	cout << " ------------" << endl;
	MyArray array3(5);

	cin >> array3;                 //调用右移操作符


	cout << "array3:" << endl;
	cout << array3 << endl;        //调用左移操作符
	cout << endl;

	
	if (array3 != array1)          //调用！=操作符重载
	{       
		cout << "不相等" << endl;
	}
	else {
		cout << "相等 " << endl;
	}

	return 0;
}
