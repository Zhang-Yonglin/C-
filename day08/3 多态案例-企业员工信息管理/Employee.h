#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//抽象的员工 
class Employee
{
public:
	Employee();
	virtual ~Employee();        //虚析构函数

	//提供一个现实的初始化员工的函数
	virtual void init() = 0;    //纯虚函数

	//提供员工薪资的计算方法
	virtual void getPay() = 0;
	
	//显示员工的信息
	void displayStatus();
	
	//提供修改员工级别的方法
	virtual void upLevel(int level) = 0;

protected:             //子类中可以进行继承访问
	string name;   //姓名
	int id;        //编号
	double salary; //薪资
	int level;     //级别

	//员工的编号基础值
	static int startNum;  //可以实现在不同对象之间数据共享  不能在头文件中进行初始化
};

//在Employee.h头文件中，定义了虚函数，在继承于这个类的其它类的头文件中，是对重写的虚函数的声明，具体实现在对应的.cpp文件中
