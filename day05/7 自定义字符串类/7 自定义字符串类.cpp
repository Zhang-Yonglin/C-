#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;


int main(void)
{

#if 1
	//string s1;
	MyString s1("abc");  //字符串长度指的是有效长度（不包含\0），而不是空间长度（包含\0）  NULL表示0值或者空指针
	MyString s2("123");  //调用有参构造
	cout << s1 << endl;
	cout << s2 << endl;
	
	MyString T;
	T = s1 + s2;
	cout << T << endl; 
	//cout << << endl;  如果直接这样写，会出错，不是返回给匿名对象吗？为什么会出错？
	cout << "程序结束，开始析构：" << endl;
#endif

	
#if 0
	MyString s1("abc");
	MyString s2(s1);
	MyString s3 = "123";

	//<<重载
	cout << s1 << endl;
	cout << s2 << endl;

	//[]重载
	s1[1] = 'x';
	cout << s1 << endl;

	//=重载
	s1 = s3;
	cout << s1 << endl;
	
	cout << "程序结束，开始析构：" << endl;

#endif

	return 0;
	
}
