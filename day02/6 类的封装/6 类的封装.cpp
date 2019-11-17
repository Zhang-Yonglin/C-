#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//定义结构体
struct Date
{
	int year;
	int month;
	int day;
};

//输入结构体中的内容  终端输入变量
void init_date(struct Date &d)       //引用传递
{
	cout << "year, month, day :" << endl;
	cin >> d.year;
	cin >> d.month;
	cin >> d.day;
}


//打印data的接口
void print_date(struct Date &d)      //引用传递
{
	cout << d.year << "年" << d.month << "月" << d.day << "日" << endl;
}


bool is_leap_year(struct Date &d)    //引用传递
{
	if (((d.year % 4 == 0) && (d.year % 100 != 0)) || (d.year % 400 == 0)) 
	{
		return true;
	}
	return false;
}


//定义类
class MyDate
{
public:
	//成员方法 成员函数
	void init_date()
	{
		cout << "year, month, day" << endl;
		cin >> year;
		cin >> month;
		cin >> day;
	}

	//打印data的接口
	void print_date()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}

	bool is_leap_year()
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			return true;
		}
		return false;
	}

	int get_year()               //类的get方法
	{
		return year;
	}

	void set_year(int new_year)  //类的set方法
	{
		year = new_year;
	}

protected:   //保护控制权限。在类的继承中跟private有区别，在单个类中，跟private是一模一样。
private:     //类的内部可以访问，在类的外部无法访问
	int year;
	int month;
	int day;
};


//一个类的内部，默认的访问控制权限是private
class Hero
{
	int year;
};


//一个结构体默认的访问控制权限的是public
struct Hero2
{
	int year;
	void print()  //在结构体中也可以写成员方法。C++中结构体与类的唯一区别是默认的访问权限不一样，剩下的都一样（struct就是一个类）
	{

	}
};


int main(void)
{

//使用结构体
#if 1
	Date d1;

	init_date(d1);
	print_date(d1);
	if (is_leap_year(d1) == true) {
		cout << "是闰年 " << endl;
	}
	else {
		cout << "不是闰年 " << endl;
	}
#endif
	cout << "--------------------" << endl;
	
	
//使用类
	MyDate my_date;

	my_date.init_date();    //初始化  即输入年月日

	my_date.print_date();   //打印年月日

	if (my_date.is_leap_year() == true)
	{
		cout << "是闰年 " << endl;
	}
	else {
		cout << "不是闰年 " << endl;
	}


	//get,set
	cout << my_date.get_year() << endl;
	my_date.set_year(2000);   //重新设置年份
	cout << my_date.get_year() << endl;


	Hero h;
	//h.year = 1000;  //外部无法修改（即无法外部访问）

	Hero2 h2;
	h2.year = 100;

	return 0;
}
