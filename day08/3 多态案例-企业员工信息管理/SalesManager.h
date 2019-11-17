#pragma once
#include "Manager.h"
#include "SalesMan.h"


class SalesManager :public Manager, public SalesMan   //多继承
{
public:
	SalesManager();
	~SalesManager();

	//初始化
	virtual void init();

	//提供员工薪资的计算方法
	virtual void getPay();

	//提供修改员工级别的方法
	virtual void upLevel(int level);    //虚函数重写（此头文件中是声明，重写的定义在对应的.cpp文件中）
};


//所需的变量已经从父类中全部继承
