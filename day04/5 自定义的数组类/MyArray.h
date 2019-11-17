#pragma once

#include <iostream>

using namespace std;


class MyArray
{
public:
	MyArray();                              //无参构造函数
	MyArray(int len);                       //有参构造函数
	MyArray(const MyArray &another);        //拷贝构造函数
	~MyArray();                             //析构函数

	void setData(int index, int data);      //设置数据
	int getData(int index);                 //获取数据
	int getLen();                           //获取长度

	void operator=(const MyArray& another); //=操作符
private:
	int len;     
	int *space;  //int类型指针  指向数组首元素的地址  space其实是一个数组名
};

