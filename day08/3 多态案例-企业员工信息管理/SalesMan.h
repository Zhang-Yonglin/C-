#pragma once
#include "Employee.h"


class SalesMan : virtual public Employee   //虚继承，防止变量重复拷贝
{
public:
	SalesMan();
	~SalesMan();

	//提供员工薪资的计算方法
	virtual void getPay();

	//初始化
	virtual void init();

	//提供修改员工级别的方法
	virtual void upLevel(int level);   //虚函数重写（此头文件中是声明，重写的定义在对应的.cpp文件中）

protected:   //不能为private，否则子类无法访问
	//当月的销售额
	int saleAmount;
	
	//提成的比率
	double salePercent;
};

