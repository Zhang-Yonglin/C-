#include <iostream>
#include <string.h>
//using namespace std;

class Employee
{
public:
    virtual void monthPay() = 0;        //纯虚函数
    virtual void displayStatus() = 0;   //纯虚函数
};


class EmployeeInfo
{
public:
    EmployeeInfo()                                    //无参构造
    {
    }

    EmployeeInfo(const char *name,int id,int status)  //有参构造
    {
        strcpy(this->name, name);
        this->id = id;
        this->status = status;
        this->pay = 0;
    }
    
    void showAll()                                    //普通成员函数
    {
        std::cout << "员工姓名: " << this->name << std::endl;
        std::cout << "员工编号: " << this->id << std::endl;
        std::cout << "员工级别: " << this->status << std::endl;
    }

    char name[32];
    int id;
    int status;
    double pay;
    static int start;           //静态成员变量
    static double monthSale;    //静态成员变量
};


int EmployeeInfo::start = 1000;         //静态成员变量初始化
double EmployeeInfo::monthSale = 0;     //静态成员变量初始化


//工程师
class Technician :public Employee,public EmployeeInfo   //多继承
{
public:
    Technician(const char *name,int status,int hours):EmployeeInfo(name,++EmployeeInfo::start,status)   //有参构造
    {
        this->hours = hours;
        this->pay = 100*hours;
    }

    virtual void monthPay()
    {
        std::cout << "\n" << "=======>>技术员<<==========" << std::endl;
        this->showAll();      //调用父类的普通成员函数
        std::cout << "员工工时: " << this->hours << std::endl;
        std::cout << "员工工资: " << this->pay << std::endl;
    }
    virtual void displayStatus()
    {
        this->status += 2;
    }
    int hours;
};


//经理
class Manager :virtual public Employee,virtual public EmployeeInfo
{
public:
    Manager()
    {
    }

    Manager(const char *name,int status):EmployeeInfo(name,++EmployeeInfo::start,status)
    {
        this->pay += 8000;
    }
    virtual void monthPay()
    {
        std::cout << "\n" << "=======>>经理<<==========" << std::endl;
        this->showAll();
        std::cout << "员工工资: " << this->pay << std::endl;
    }
    virtual void displayStatus()
    {
        this->status += 3;
    }
};


//销售员
class Saleman :virtual public Employee,virtual public EmployeeInfo
{
public:
    Saleman()
    {
    }

    Saleman(const char *name,int status,double ms):EmployeeInfo(name,++EmployeeInfo::start,status)
    {
        this->ems = ms;
        this->pay = ms*0.04;

        EmployeeInfo::monthSale += ms;
    }
    virtual void monthPay()
    {
        std::cout << "\n" << "=======>>销售员<<==========" << std::endl;
        this->showAll();
        std::cout << "月销售额: " << this->ems << std::endl;
        std::cout << "员工工资: " << this->pay << std::endl;
    }
    virtual void displayStatus()
    {

    }
    double ems;
};


//销售经理
class SaleManager :public Manager,public Saleman
{
public:
    SaleManager(const char *name,int status)
    {
        strcpy(this->name,name);
        this->id = ++EmployeeInfo::start;
        this->status = status;
        this->pay = 5000 + (EmployeeInfo::monthSale * 0.05);
    }
    virtual void monthPay()
    {
        std::cout << "\n" << "=======>>销售经理<<==========" << std::endl;
        this->showAll();
        std::cout << "员工工资: " << this->pay << std::endl;
        std::cout << "月销售总额: " << EmployeeInfo::monthSale << std::endl;


    }
    virtual void displayStatus()
    {
        this->status += 3;
    }
};


void printInfo(Employee * ep)
{
    ep->displayStatus();   //调用员工级别计算函数
    ep->monthPay();        //调用打印薪资函数
    
    if (ep != NULL) {
	delete ep;
	ep = NULL;
	}
    
    return;                //此处不可以写成：return 0;  因为此函数无返回值
}


int main()
{
    Technician *tc = new Technician("范余飞",1,224);
    Manager *mg = new Manager("刘楠",1);
    Saleman *sm1 = new Saleman("郭星辉",1,300000);
    Saleman *sm2 = new Saleman("王超",1,280000);
    Saleman *sm3 = new Saleman("李超超",1,250000);
    Employee *sm = new SaleManager("芦威",1);     //父类指针可以指向子类对象
    
    Employee *arr[] = {tc,mg,sm1,sm2,sm3,sm};    //指针数组定义及初始化  数组类型为Employee类的指针类型，但是初始化的值中有子类指针，此处是：父类指针指向子类对象，这是可以的

    int i = 0;
    for(i = 0; i<6;i++)
    {
        printInfo(arr[i]);
    }

    //delete tc;                                 //如果这行代码也执行，则会重复释放，发生段错误  因为main函数中已经进行了释放
    
    return 0;
}

