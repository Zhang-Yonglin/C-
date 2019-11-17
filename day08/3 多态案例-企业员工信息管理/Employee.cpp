#include "Employee.h"

//员工编号初始化
int Employee::startNum = 1000;  //静态数据初始化


Employee::Employee()            //无参构造  构造函数中不要写一些业务，只写一些变量的初始化
{
	cout << "Employee()..." << endl;
	id = startNum++;
	level = 1;
	salary = 0.0;
}


Employee::~Employee()          //析构函数
{
	cout << "~Employee().." << endl;
}


void Employee::displayStatus() //打印函数
{
	cout << "员工姓名：" << this->name << endl;
	cout << "员工的级别：" << this->level << endl;
	cout << "员工的月薪：" << this->salary << endl;
	cout << "员工的ID：" << this->id << endl;
}
