#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Circle.h"  //引入类的头文件

using namespace std;

int main(void)
{
	Circle c;   //定义对象
	c.setR(10);

	cout << "面积:" << c.getArea() << endl;  //调用类中的成员方法（成员函数）

	return 0;
}
