#pragma once
#include <iostream>

using namespace std;


class MyArray
{
public:
	MyArray();                        //默认
	MyArray(int len);                 //有参
	MyArray(const MyArray &another);  //拷贝
	~MyArray();                       //析构

	void setData(int index, int data); //设置
	int getData(int index);            //获取元素
	int getLen() const ;               //获取数组长度

	MyArray& operator=(const MyArray& another);  //=操作符 返回引用

	int & operator[](int index) const;           //[]操作符  返回引用

	friend ostream &operator<<(ostream &os,const MyArray &array);  //友元函数（重载左移操作符）
	friend istream &operator>>(istream &is, MyArray &array);

	friend bool operator==(MyArray &array1, MyArray &array2);
	bool operator!=(MyArray &another);  //成员函数
private:
	int len;
	int *space;
};




