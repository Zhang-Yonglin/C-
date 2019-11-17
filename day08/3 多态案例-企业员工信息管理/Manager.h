#pragma once
#include "Employee.h"


class Manager : virtual public Employee  //虚继承  防止变量重复拷贝
{
public:
	Manager();
	~Manager();

	//提供一个现实的初始化员工的函数
	virtual void init();

	//计算薪资
	virtual void getPay();

	//提供修改员工级别的方法
	virtual void upLevel(int level);  //虚函数重写（此头文件中是声明，重写的定义在对应的.cpp文件中）

protected:   //不能为private，否则子类无法访问
	double fixSalary;  //经理的固定工资
};

