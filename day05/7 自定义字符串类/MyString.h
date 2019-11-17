#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;


class MyString
{
public:
	MyString();
	//MyString(int len);                 //创建一个长度是len的string对象
	MyString(const char *str);           //有参构造
	MyString(const MyString &another);   //拷贝构造函数
	~MyString();

	//重载操作符[]
	char &operator[](int index);         //返回引用

	//重载操作符>>
	friend istream & operator>>(istream &is, MyString &s);  //友元函数

	//重载=操作符
	MyString & operator=(const MyString &another);

	//重载==操作符

	//重载!=操作符

	//重载+操作符
	MyString operator+(MyString &another);

	//重载操作符<<
	friend ostream & operator<<(ostream &os, MyString&s);  //友元函数实现重载操作符

private:
	int len;
	char *str;
};

