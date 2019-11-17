#include "Manager.h"


//构造
Manager::Manager()
{
	cout << "Manager().." << endl;

}


//初始化
void Manager::init()
{
	cout << "请输入经理的姓名" << endl;
	cin >> name;
	this->fixSalary = 8000;
}


//析构
Manager::~Manager()
{
	cout << "~Manager().." << endl;
}


//计算薪资
void Manager::getPay()
{
	//计算薪水的方式
	this->salary = this->fixSalary;  //固定薪资
}


//提供修改员工级别的方法
void Manager::upLevel(int level) {
	this->level += level;

	//不同级别的经理薪资不同
	if (this->level == 1) {
		this->fixSalary = 8000;
	}
	
	else if(this->level == 2){
		this->fixSalary = 10000;
	}
}
