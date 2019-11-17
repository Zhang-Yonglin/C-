#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//程序员类
class Programmer
{
public:
	Programmer(double salary)       //有参构造
	{
		this->salary = salary;
	}
	virtual void printMoney() = 0;  //纯虚构函数
	virtual ~Programmer() {         //纯析构函数

	}

protected:
	double salary;
};


//初级程序员类
class Junior_programmer :public Programmer
{
public:
	Junior_programmer(double salary) :Programmer(salary) {       //有参构造

	}
	virtual void printMoney(){
		cout << "初级程序员的工资是" << this->salary << endl;
	}
};


//中级程序类
class Mid_programmer :public Programmer
{
public:
	Mid_programmer(double salary) :Programmer(salary) {          //有参构造

	}
	virtual void printMoney(){
		cout << "中级程序员的工资是" << this->salary << endl;
	}
};


//高级程序员类
class Adv_programmer :public Programmer
{
public:
	Adv_programmer(double salary) :Programmer(salary) {          //有参构造

	}
	virtual void printMoney(){
		cout << "高级程序员的工资是" << this->salary << endl;
	}
};


int main(void)
{

	Programmer * pro1 = new Junior_programmer(12000);  //父类指针指向子对象
	pro1->printMoney();
	delete pro1;

	Programmer * pro2 = new Mid_programmer(15000);     //父类指针指向子对象
	pro2->printMoney();
	delete pro2;

	Programmer *pro3 = new Adv_programmer(30000);      //父类指针指向子对象
	pro3->printMoney();
	delete pro3;

	return 0;
	
}
