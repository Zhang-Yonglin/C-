#pragma once
#include "Employee.h"


class Technician : public Employee
{
public:
	Technician();
	~Technician();

	//初始化
	virtual void init();

	//提供员工薪资的计算方法
	virtual void getPay();

	//升级的方法
	virtual void upLevel(int level);    //虚函数重写（此头文件中是声明，重写的定义在对应的.cpp文件中）
private:
	//一个月工作了多少小时
	int workHour;
	
	//每小时多钱
	double perHourMoney;
};

